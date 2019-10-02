/*
 * Kotlin has built-in support for extension functions for any existing
 * types. Using these can effectively limit the need for static helper
 * classes within your projects.
 */

// Example 1: Get an argument list from a string
fun String.args(): Array<String> {
    return this.split("").toTypedArray()
}

/*
 * Kotlin also supports overriding operators on most existing classes.
 */

// Example 2: Add a minus operator to the string class for removing words
operator fun String.minus(remove: String): String {
    return this.replace(remove, "")
}

fun foo(): String {
    return "foobar" - "bar" // Results in "foo"
}

/*
 * The use of generics also enabled more complex operators to be created.
 */

// Example 3: Generic number function for adding a number to every element in an array
operator fun <T : Number> Array<T>.plus(number: Number): Array<in Number> {
    return this.map { it.toDouble().plus(number.toDouble()) }.toTypedArray()
}

// Functions may also be reduced to an equals
// assignment if they are only single line.
fun bar() = arrayOf(1, 2, 3, 4, 5) + 5 // Returns an array of 6, 7, 8, 9, 10