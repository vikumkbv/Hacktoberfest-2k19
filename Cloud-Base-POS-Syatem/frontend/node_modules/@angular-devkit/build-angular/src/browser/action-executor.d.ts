export declare class ActionExecutor<Input extends {
    size: number;
}, Output> {
    private readonly actionName;
    private largeWorker;
    private smallWorker;
    private smallThreshold;
    constructor(actionFile: string, actionName: string);
    execute(options: Input): Promise<Output>;
    executeAll(options: Input[]): Promise<Output[]>;
    stop(): void;
}
