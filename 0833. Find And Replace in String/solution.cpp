class Solution {
public:
    // Method to perform find and replace in a string given specific indices, sources, and targets.
    string findReplaceString(string str, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int strSize = str.size();
        // Create a lookup array to associate indices in the main string with their replacement index, initialized as -1.
        vector<int> replacementIndex(strSize, -1);

        // Loop through each index provided to calculate the replacement index.
        for (int i = 0; i < indices.size(); ++i) {
            int index = indices[i];
            // Only set the replacement index if the source matches the substring starting at index.
            if (str.compare(index, sources[i].size(), sources[i]) == 0) {
                replacementIndex[index] = i;
            }
        }

        string result; // Initialize the result string which will accumulate the final output.

        // Iterate through the original string by character.
        for (int i = 0; i < strSize;) {
            // If the current index has a valid replacement index, concatenate the target string.
            if (replacementIndex[i] != -1) {
                result += targets[replacementIndex[i]];
                // Move the index forward by the length of the source that was replaced.
                i += sources[replacementIndex[i]].size();
            } else {
                // If there's no replacement, just append the current character to the result.
                result += str[i++];
            }
        }

        // Return the modified string after all replacements are done.
        return result;
    }
};
