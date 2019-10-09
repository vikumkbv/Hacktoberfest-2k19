"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
/**
 * @license
 * Copyright Google Inc. All Rights Reserved.
 *
 * Use of this source code is governed by an MIT-style license that can be
 * found in the LICENSE file at https://angular.io/license
 */
const jest_worker_1 = require("jest-worker");
const os = require("os");
class ActionExecutor {
    constructor(actionFile, actionName) {
        this.actionName = actionName;
        this.smallThreshold = 32 * 1024;
        // larger files are processed in a separate process to limit memory usage in the main process
        this.largeWorker = new jest_worker_1.default(actionFile, {
            exposedMethods: [actionName],
        });
        // small files are processed in a limited number of threads to improve speed
        // The limited number also prevents a large increase in memory usage for an otherwise short operation
        this.smallWorker = new jest_worker_1.default(actionFile, {
            exposedMethods: [actionName],
            numWorkers: os.cpus().length < 2 ? 1 : 2,
            // Will automatically fallback to processes if not supported
            enableWorkerThreads: true,
        });
    }
    execute(options) {
        if (options.size > this.smallThreshold) {
            return this.largeWorker[this.actionName](options);
        }
        else {
            return this.smallWorker[this.actionName](options);
        }
    }
    executeAll(options) {
        return Promise.all(options.map(o => this.execute(o)));
    }
    stop() {
        this.largeWorker.end();
        this.smallWorker.end();
    }
}
exports.ActionExecutor = ActionExecutor;
