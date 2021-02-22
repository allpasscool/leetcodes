class FileSystem {
public:
    FileSystem() {
        dirs["/"];
    }
    
    vector<string> ls(string path) {
        if (files.count(path)) {
            int idx = path.find_last_of('/');
            return {path.substr(idx + 1)};
        }
        
        auto files_ans = dirs[path];
        return vector<string> (files_ans.begin(), files_ans.end());
    }
    
    void mkdir(string path) {
        // Object class of istringstream 
        istringstream my_stream(path);
        string str = "", dir = "";
        
        while (getline(my_stream, str, '/')) {
            if (str.empty()) continue;
            if (dir.empty()) dir += "/";
            
            dirs[dir].insert(str);
            if (dir.size() > 1) dir += "/";
            dir += str;
        }
    }
    
    void addContentToFile(string filePath, string content) {
        int idx = filePath.find_last_of('/');
        string dir = filePath.substr(0, idx);
        string file = filePath.substr(idx + 1);
        if (dir.empty()) dir = "/";
        if (!dirs.count(dir)) mkdir(dir);
        dirs[dir].insert(file);
        files[filePath].append(content);
    }
    
    string readContentFromFile(string filePath) {
        return files[filePath];
    }
    
private:
    unordered_map<string, set<string>> dirs;
    unordered_map<string, string> files;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

// Runtime: 28 ms, faster than 77.11% of C++ online submissions for Design In-Memory File System.
// Memory Usage: 15.8 MB, less than 16.45% of C++ online submissions for Design In-Memory File System.
// https://www.cnblogs.com/grandyang/p/6944331.html