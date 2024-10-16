Lost and Found Project - Software Design Document (SDD)
Overview
This project details the Lost and Found system, which assists users in reporting and retrieving lost items. It includes a policeman to handle requests and manage the application. This document outlines the system's design, data structure, interaction flows, and algorithms used in developing the system.

Key Features
User Reports: Allows users to report lost or found items.
Admin Controls: Admins can verify reports and manage system data.
Notifications: Users receive updates about their reports and potential matches.
Security: Users are required to answer security questions to claim found items.
Diagrams Included
System Context Diagram: Illustrates the high-level interaction between users, admins, the system, and the database.
Class Diagram: Depicts the structure and relationships of entities within the system, such as users, reports, and notifications.
Sequence Diagram: Describes the flow of events, such as reporting a lost item or verifying a claim.
Use Case Diagram: Highlights the main functionalities, including item reporting, claim verification, and item searching.
Activity Diagram: Shows the different states in the lifecycle of a report (submitted, verified, claimed).
N-tier Architecture Diagram: Outlines the system's architecture with presentation, logic, and data layers.
System Design
Frontend: Implemented using HTML, CSS, and JavaScript for a responsive and user-friendly interface.
Backend: Built with Node.js and Express to handle requests and interact with the database.
Database: Utilizes SQL to store and manage user data, item reports, claims, and notifications.
Algorithms
Item Matching Algorithm: Matches lost items with found items based on various attributes such as location, category, and date.
Notification Algorithm: Sends notifications to users when potential matches are found or claims are updated.
Search Algorithm: Allows users to search for lost or found items based on specified criteria.
Claim Verification Algorithm: Validates user claims using security questions.
Project Management
The project includes a comprehensive Gantt chart, team roles, and project milestones. Each phase from initiation to deployment and maintenance is clearly outlined, ensuring efficient project execution.
