#include <iostream>
#include <vector>
#include "1-User.cpp"             
#include "1a-Role.cpp"
#include "5-FileSharingSystem.cpp"
using namespace std;

int main() {
    // Create users (admin and regular user)
    User* admin = new User("adminUser", "adminPass", ADMIN);
    User* user1 = new User("user1", "user1Pass", USER);

    // Get the FileSharingSystem singleton instance
    FileSharingSystem* fsSystem = FileSharingSystem::getInstance();

    // Register the users in the system (this creates their root folders)
    fsSystem->registerUser(admin);
    fsSystem->registerUser(user1);

    try {
        // For user1, add a "Documents" folder at the root
        fsSystem->addFolder(user1, "", "Documents");

        // Within "Documents", add a subfolder called "Photos"
        fsSystem->addFolder(user1, "Documents", "Photos");

        // Add a file "resume.pdf" (50KB) inside "Documents"
        fsSystem->addFile(user1, "Documents", "resume.pdf", 50000);

        // Rename "resume.pdf" to "resume_updated.pdf"
        fsSystem->renameComponent(user1, "Documents/resume.pdf", "resume_updated.pdf");

        // Update file content. Suppose the update increases the file size by 10KB
        fsSystem->updateFileContent(user1, "Documents/resume_updated.pdf", "Updated resume content", 10000);

        // Update permissions: grant READ permission to admin for user1's file
        fsSystem->updatePermissions(user1, "Documents/resume_updated.pdf", admin, READ);

        // Search for components with "resume" in their name in user1's hierarchy
        vector<FileSystemComponent*> results = fsSystem->search(user1, "resume");
        cout << "Search results for 'resume':" << endl;
        for (auto comp : results) {
            comp->display("  ");
        }

        // Delete the file. We pass the total file size (50KB + 10KB update) to update the user's storage usage
        fsSystem->deleteComponent(user1, "Documents/resume_updated.pdf", 60000);

        // Display user1's full file hierarchy
        cout << "\nUser1's file hierarchy:" << endl;
        fsSystem->getUserRoot(user1)->display("");
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
