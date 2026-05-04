#if defined _outputinfo_included
    #endinput
#endif
#define _outputinfo_included

/**
 * Returns the number of actions registered for the given output.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 *
 * @return              Number of actions, or 0 if the output does not exist.
 */
native int GetOutputCount(int entity, const char[] output);

/**
 * Retrieves the target name of an output action at the given index.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param index         Action index. Use FindOutput() to locate a specific action.
 * @param target        Buffer to store the target name.
 * @param maxlen        Maximum length of the output buffer.
 *
 * @return              Number of bytes written to the buffer.
 */
native int GetOutputTarget(int entity, const char[] output, int index, char[] target, int maxlen);

/**
 * Retrieves the target input of an output action at the given index.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param index         Action index. Use FindOutput() to locate a specific action.
 * @param targetInput   Buffer to store the target input.
 * @param maxlen        Maximum length of the output buffer.
 *
 * @return              Number of bytes written to the buffer.
 */
native int GetOutputTargetInput(int entity, const char[] output, int index, char[] targetInput, int maxlen);

/**
 * Retrieves the parameter of an output action at the given index.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param index         Action index. Use FindOutput() to locate a specific action.
 * @param parameter     Buffer to store the parameter.
 * @param maxlen        Maximum length of the output buffer.
 *
 * @return              Number of bytes written to the buffer.
 */
native int GetOutputParameter(int entity, const char[] output, int index, char[] parameter, int maxlen);

/**
 * Retrieves the delay of an output action at the given index.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param index         Action index. Use FindOutput() to locate a specific action.
 *
 * @return              Delay in seconds, or -1.0 if the output does not exist.
 */
native float GetOutputDelay(int entity, const char[] output, int index);

/**
 * Retrieves the refire count of an output action at the given index.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param index         Action index. Use FindOutput() to locate a specific action.
 *
 * @return              Number of times the action will fire (-1 = infinite), or 0 on failure.
 */
native int GetOutputRefires(int entity, const char[] output, int index);

/**
 * Retrieves a formatted string representation of an output action at the given index.
 * Format: "target,targetInput,parameter,delay,timesToFire"
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param index         Action index. Use FindOutput() to locate a specific action.
 * @param formatted     Buffer to store the formatted string.
 * @param maxlen        Maximum length of the output buffer.
 *
 * @return              Number of bytes written to the buffer.
 */
native int GetOutputFormatted(int entity, const char[] output, int index, char[] formatted, int maxlen);

/**
 * Retrieves the integer value stored in the given output.
 * Throws a native error if the output value type is not an integer.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 *
 * @return              Integer value of the output.
 */
native int GetOutputValue(int entity, const char[] output);

/**
 * Retrieves the float value stored in the given output.
 * Throws a native error if the output value type is not a float.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 *
 * @return              Float value of the output.
 */
native float GetOutputValueFloat(int entity, const char[] output);

/**
 * Retrieves the string value stored in the given output.
 * Throws a native error if the output value type is not a string.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param buffer        Buffer to store the string value.
 * @param maxlen        Maximum length of the output buffer.
 *
 * @return              Number of bytes written to the buffer.
 */
native int GetOutputValueString(int entity, const char[] output, char[] buffer, int maxlen);

/**
 * Retrieves the vector value stored in the given output.
 * Throws a native error if the output value type is not a vector.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param vec           Float array of size 3 to store the vector.
 *
 * @return              True on success, false otherwise.
 */
native bool GetOutputValueVector(int entity, const char[] output, float vec[3]);

/**
 * Searches for an output action matching the given criteria, starting from startIndex.
 * Pass an empty string or default values to ignore a specific field.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param startIndex    Index to start searching from.
 * @param target        Target name to match, or NULL_STRING to ignore.
 * @param targetInput   Target input to match, or NULL_STRING to ignore.
 * @param parameter     Parameter to match, or NULL_STRING to ignore.
 * @param delay         Delay value to match, or -1.0 to ignore.
 * @param timesToFire   Refire count to match, or 0 to ignore.
 *
 * @return              Index of the matching action, or -1 if not found.
 */
native int FindOutput(
    int entity,
    const char[] output,
    int startIndex,
    const char[] target      = NULL_STRING,
    const char[] targetInput = NULL_STRING,
    const char[] parameter   = NULL_STRING,
    float delay              = -1.0,
    int timesToFire          = 0
);

/**
 * Deletes the output action at the given index.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 * @param index         Action index. Use FindOutput() to locate a specific action.
 *
 * @return              True on success, false otherwise.
 */
native bool DeleteOutput(int entity, const char[] output, int index);

/**
 * Deletes all actions registered for the given output.
 *
 * @param entity        Entity index.
 * @param output        Output property name.
 *
 * @return              Number of actions deleted.
 */
native int DeleteAllOutputs(int entity, const char[] output);

/**
 * Retrieves the name of an output at the given index by iterating the entity's datamap.
 *
 * @param entity        Entity index.
 * @param index         Output index in the datamap.
 * @param output        Buffer to store the output name.
 * @param maxlen        Maximum length of the output buffer.
 *
 * @return              Number of bytes written to the buffer.
 */
native int GetOutputNames(int entity, int index, char[] output, int maxlen);

#if !defined REQUIRE_PLUGIN
public void __pl_OUTPUTINFO_SetNTVOptional()
{
    MarkNativeAsOptional("GetOutputCount");
    MarkNativeAsOptional("GetOutputTarget");
    MarkNativeAsOptional("GetOutputTargetInput");
    MarkNativeAsOptional("GetOutputParameter");
    MarkNativeAsOptional("GetOutputDelay");
    MarkNativeAsOptional("GetOutputRefires");
    MarkNativeAsOptional("GetOutputFormatted");
    MarkNativeAsOptional("GetOutputValue");
    MarkNativeAsOptional("GetOutputValueFloat");
    MarkNativeAsOptional("GetOutputValueString");
    MarkNativeAsOptional("GetOutputValueVector");
    MarkNativeAsOptional("FindOutput");
    MarkNativeAsOptional("DeleteOutput");
    MarkNativeAsOptional("DeleteAllOutputs");
    MarkNativeAsOptional("GetOutputNames");
}
#endif

public SharedPlugin __pl_OUTPUTINFO =
{
    name = "outputinfo",
    file = "outputinfo.smx",
#if defined REQUIRE_PLUGIN
    required = 1,
#else
    required = 0,
#endif
};
