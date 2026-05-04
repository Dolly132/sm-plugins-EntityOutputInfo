#if defined _OUTPUTINFO_included
 #endinput
#endif
#define _OUTPUTINFO_included


native int DeleteOutput(int Entity, const char[] sOutput, int Index);
native int DeleteAllOutputs(int Entity, const char[] sOutput);
/*
 * Retrieves the number of elements of the given output.
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 *
 * @return					The number of elements of the given output.
 */
native int GetOutputCount(int entity, const char[] output);

/*
 * Retrieves the target name of the given output at specific index. (Use FindOutput to get the index)
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param index				The index of the output. (See FindOutput).
 * @param target			The buffer to store the target name in.
 * @param maxlen			The maximum length of the outgiven buffer.
 *
 * @return					The number of bytes written to buffer.
 */
native int GetOutputTarget(int entity, const char[] output, int index, char[] target, int maxlen);

/*
 * Retrieves the target input of the given output at specific index. (Use FindOutput to get the index)
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param index				The index of the output. (See FindOutput).
 * @param targetInput		The buffer to store the target input in.
 * @param maxlen			The maximum length of the outgiven buffer.
 *
 * @return					The number of bytes written to buffer.
 */
native int GetOutputTargetInput(int entity, const char[] output, int index, char[] targetInput, int maxlen);

/*
 * Retrieves the parameter of the given output at specific index. (Use FindOutput to get the index)
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param index				The index of the output. (See FindOutput).
 * @param parameter			The buffer to store the parameter in.
 * @param maxlen			The maximum length of the outgiven buffer.
 *
 * @return					The number of bytes written to buffer.
 */
native int GetOutputParameter(int entity, const char[] output, int index, char[] parameter, int maxlen);

/*
 * Retrieves the delay of the given output at specific index. (Use FindOutput to get the index)
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param index				The index of the output. (See FindOutput).
 *
 * @return					The delay value of the output.
 */
native float GetOutputDelay(int entity, const char[] output, int index);

/*
 * Retrieves the refires count of the given output at specific index. (Use FindOutput to get the index)
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param index				The index of the output. (See FindOutput).
 *
 * @return					The refires value of the output.
 */
native int GetOutputRefires(int entity, const char[] output, int index);

/*
 * Retrieves the output at given index with proper display.
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param index				The index of the output. (See FindOutput).
 * @param formatted			The buffer to store the formatted output in.
 * @param maxlen			The maximum length of the outgiven buffer.
 *
 * @return					The number of bytes written to buffer.
 */
native int GetOutputFormatted(int entity, const char[] output, int index, char[] formatted, int maxlen);

/*
 * Retrieves the integer value of the given output.
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 *
 * @return					The value of the given output.
 */
native int GetOutputValue(int entity, const char[] output);

/*
 * Retrieves the float value of the given output.
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 *
 * @return					The value of the given output.
 */
native float GetOutputValueFloat(int entity, const char[] output);

/*
 * Retrieves the string value of the given outpout.
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param buffer			The buffer to store the string value in.
 * @param maxlen			The maximum length of the outgiven buffer.
 *
 * @return					The number of bytes written to buffer.
 */
native int GetOutputValueString(int entity, const char[] output, char[] buffer, int maxlen);

/*
 * Retrieves the vector value of the given outpout.
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param vec				The vector array (float[3]).
 *
 * @return					True on success, false otherwise.
 */
native bool GetOutputValueVector(int entity, const char[] output, float vec[3]);

/*
 * Retrieves the output index based on given rules.
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param startIndex		Where should the iterations start from.
 * @param target			The target name to search for, or NULL_STRING to ignore.
 * @param targetInput		The target input to search for, or NULL_STRING to ignore.
 * @param parameter			The parameter to search for, or NULL_STRING to ignore.
 * @param delay				The delay value to search for, or -1.0 to ignore.
 * @param timesToFire		The number of refires to search for, or 0 to ignore.
 *
 * @return					The output index, -1 on failure.
 */
native int FindOutput(
	int entity,
	const char[] output,
	int startIndex,
	const char[] target = NULL_STRING,
	const char[] targetInput = NULL_STRING,
	const char[] parameter = NULL_STRING,
	float delay = -1.0,
	int timesToFire = 0
);

/*
 * Delete the output at specific index. (Use FindOutput to get the index)
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 * @param index				The index of the output. (See FindOutput).
 *
 * @return					True on success, false otherwise.
 */
native bool DeleteOutput(int entity, const char[] output, int index);

/*
 * Delete all outputs from an entity.
 *
 * @param entity			The entity index.
 * @param output			The output property name.
 *
 * @return					The number of outputs deleted.
 */
native int DeleteAllOutputs(int entity, const char[] output);

#if !defined REQUIRE_PLUGIN
public void __pl_INTERFACE_SetNTVOptional()
{
	MarkNativeAsOptional("GetOutputCount");
	MarkNativeAsOptional("GetOutputTarget");
	MarkNativeAsOptional("GetOutputTargetInput");
	MarkNativeAsOptional("GetOutputParameter");
	MarkNativeAsOptional("GetOutputDelay");
	MarkNativeAsOptional("GetOutputRefires");
	MarkNativeAsOptional("GetOutputFormatted");
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
