class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string token;

        // Split the path by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Skip empty or current directory "."
                continue;
            } else if (token == "..") {
                // Go one level up if not already at root
                if (!st.empty()) st.pop();
            } else {
                // Valid directory name
                st.push(token);
            }
        }

        // Build the simplified path from stack
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        // If stack was empty (root), return "/"
        return result.empty() ? "/" : result;
    }
};
