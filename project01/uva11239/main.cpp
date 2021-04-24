#include <bits/stdc++.h>

using namespace std;

bool is_project (const string &line)
{
    if (any_of(line.begin(), line.end(), [](unsigned char c){ return isupper(c); }))
    {
        return true;
    }
    return false;
}

void remove_student (const string &id, map <string, set<string>> &projects)
{
    for (auto it = projects.begin(); it != projects.end(); ++it)
    {
        if (it->second.find(id) != it->second.end())
        {
            it->second.erase(id);
        }
    }
}

bool cmp (pair <string, set<string>> &a, pair <string, set<string>> &b)
{
    if (a.second.size() == b.second.size())
    {
        return a.first < b.first;
    }
    return a.second.size() > b.second.size();
}

void sort_and_print (map <string, set<string>> &m)
{
    vector <pair <string, set<string>>> v;
    
    for (auto &it : m)
    {
        v.push_back(it);
    }
    
    sort (v.begin(), v.end(), cmp);
    
    for (auto &it : v)
    {
        cout << it.first << " " << it.second.size() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string line, project_name;
    while (2 + 2 != 5)
    {
        map <string, set<string>> projects;     //  projects     and student_id's
        map <string, set<string>> students;     //  student_id's and projects 
        vector<string> v;

        while (getline(cin, line))
        {
            if (line == "0" or line == "1") break;
            
            if (is_project(line))
            {
                project_name = line;
                v.emplace_back(project_name);

                projects[project_name];             // initialize project with no value
                continue;
            }
            // if we're here, then we are reading student's id (line)
            
            students[line].insert(project_name);
            projects[project_name].insert(line); 
        }
        if (line == "1")
        {
            for (auto it = students.begin(); it != students.end(); ++it)
            {
                if (it->second.size() > 1)        // if the students is taking another course
                {
                    remove_student (it->first, projects);
                }
            }
            sort_and_print(projects);
        }
        if (line == "0") return 0;
    }
}