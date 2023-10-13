# CareerQuest: Job Tracker and Analyzer

## Purpose

CareerQuest is a command-line job tracker and analyzer program designed to help users efficiently manage their job applications and gain insights into their job search journey. This program streamlines the job application process and provides tools for tracking application status, categorizing applications, and analyzing application statistics.

## Functionality

CareerQuest offers the following key features:

- **Job Application Tracking**: Users can add, update, and remove job applications, including details such as job title, company, application status, application date, and more.

- **Custom Data Structures**: CareerQuest employs custom data structures, including `StackQueue` for managing updates and `BucketStack` for storing job applications efficiently.

- **Analytics**: The program provides a built-in analytics tool to view statistics related to job applications. Users can gain insights into their application progress and success rate.

- **User Interface**: The command-line interface is user-friendly, with a menu-driven system that guides users through various actions and options.

- **Data Persistence**: CareerQuest supports data persistence, allowing users to save and load job application data across sessions.

## Usage

To run CareerQuest, follow these steps:

1. Ensure you have a C compiler (e.g., GCC) installed on your system.

2. Clone or download the source code for CareerQuest.

3. Compile the source code using your C compiler (e.g., `gcc -o career_quest main.c bucketstack.c squeue.c`).

4. Run the compiled program (`./career_quest`).

5. Use the main menu to add, update, and view job applications and analytics.

## Custom Data Structures

CareerQuest employs custom data structures for efficient data management:

- **BucketStack**: This data structure efficiently stores job applications. It allows users to categorize and organize their applications into different buckets, making it easy to manage a large number of applications.

- **StackQueue**: StackQueue is used for managing updates to job applications. It provides a structured way to handle real-time updates and changes to application statuses.

## Notes

- CareerQuest simplifies the job application process and helps users stay organized in their job search.

- The program is designed to be customizable and extendable, making it suitable for users at various stages of their careers.

- CareerQuest demonstrates the use of custom data structures and principles of metaprogramming for code generation and manipulation.

## Contact

If you have any questions or feedback about CareerQuest, please feel free to reach out. You can contact me on GitHub: [github.com/yourusername](https://github.com/yourusername).
