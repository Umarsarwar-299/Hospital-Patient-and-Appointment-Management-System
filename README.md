# Hospital-Patient-and-Appointment-Management-System

# Hospital Patient and Appointment Management System
### Database Systems Project Report 

---

## 👥 Group Members (Group 5)
* **Khubaib Imran** (Admin)
* **Fahad Ali**
* **Ayyan Ahmad**
* **Omar Sarwar**
* **Mahnoor**
* **Mehrunnisa**

---

## 1. Introduction
[cite_start]The **Hospital Patient and Appointment Management System** is a database project designed to manage hospital operations efficiently[cite: 5]. [cite_start]The system securely tracks patient profiles, medical doctor schedules, operational appointments, prescription data, and financial billing statements[cite: 6]. 

[cite_start]Built using **SQL** and **MySQL Workbench**, the project demonstrates both foundational and advanced database concepts, including primary/foreign key table relationships, automated server-side procedures, defensive triggers, and optimized data filtering[cite: 7]. [cite_start]This localized automation prevents systemic data redundancy and drastically reduces the manual paperwork burden on healthcare staff[cite: 8].

---

## 2. Objectives
* [cite_start]**Digital Records Management:** To secure, persist, and easily query patient profiles and histories electronically[cite: 11].
* [cite_start]**Staff Tracking:** To maintain accurate schedules, department allocations, and contact parameters for medical doctors[cite: 12].
* [cite_start]**Automated Workflows:** To automate appointment booking queues and compute patient billing records instantly via backend triggers[cite: 13].
* [cite_start]**Data Integrity:** To avoid concurrent booking conflicts or scheduling duplication through relational constraints[cite: 14].
* [cite_start]**Practical Application:** To apply relational database theory (DDL/DML scripting, procedures, normalization) to a real-world enterprise situation[cite: 15].

---

## 3. Problem Statement
[cite_start]Traditional paper-based or un-indexed spreadsheet recording practices in hospital administration consistently create critical challenges, such as mismanaged clinical appointments, data conflicts, and slow manual billing generation[cite: 17]. [cite_start]Without synchronized tracking, patients experience double-booked slots, and administrative workers waste substantial time manually creating financial receipts[cite: 18]. 

[cite_start]This project resolves these clinical issues by building a clean relational architecture where patient status changes, appointment requests, doctor timetables, and invoices are instantly updated across the entire network[cite: 19].

---

## 4. System Features
* [cite_start]**Patient Profiles:** Comprehensive data collection including names, contact keys, ages, and medical genders[cite: 21].
* [cite_start]**Doctor Roster Scheduling:** Maintains strict lookups for specialized fields, specific contact numbers, and office emails[cite: 22].
* [cite_start]**Smart Scheduling:** Links appointments directly to specific calendar dates and times, preventing overlapping timeslots[cite: 23].
* [cite_start]**Automated Ledger Invoicing:** Utilizes server-side triggers to instantly generate billing entries as soon as appointments are entered[cite: 24].
* [cite_start]**Medical Prescription Ledger:** Safely matches diagnostic descriptions and pharmaceutical dosages to corresponding appointment events[cite: 25].

---

## 5. Tools and Technologies Used

| Technology Category | Specification & Operational Role |
| :--- | :--- |
| **RDBMS Engine** | [cite_start]MySQL Server 8.0+ (Provides transactional data execution) [cite: 27] |
| **Visual Modeling / IDE** | [cite_start]MySQL Workbench (Used for DDL/DML authoring and schema visualization) [cite: 27] |
| **Query Language** | [cite_start]Structured Query Language (SQL) for database building and reporting [cite: 27] |

---

## 6. Database Design
[cite_start]The layout features **5 central tables** linked together through strict relational foreign keys[cite: 29]. [cite_start]This architecture ensures that change tracking flows correctly across records while explicitly preventing orphaned files[cite: 30].

### 6.1 Patients Table
| Field Name | Data Type | Constraint / Core Purpose |
| :--- | :--- | :--- |
| **patient_id** | INT | [cite_start]PRIMARY KEY, AUTO_INCREMENT [cite: 32] |
| **name** | VARCHAR(100) | [cite_start]NOT NULL [cite: 32] |
| **age** | INT | [cite_start]NOT NULL [cite: 32] |
| **gender** | VARCHAR(10) | [cite_start]NOT NULL [cite: 32] |
| **phone** | VARCHAR(15) | [cite_start]NOT NULL [cite: 32] |
| **address** | TEXT | [cite_start]OPTIONAL [cite: 32] |

### 6.2 Doctors Table
| Field Name | Data Type | Constraint / Core Purpose |
| :--- | :--- | :--- |
| **doctor_id** | INT | [cite_start]PRIMARY KEY, AUTO_INCREMENT [cite: 34] |
| **name** | VARCHAR(100) | [cite_start]NOT NULL [cite: 34] |
| **specialization** | VARCHAR(100) | [cite_start]NOT NULL [cite: 34] |
| **phone** | VARCHAR(15) | [cite_start]NOT NULL [cite: 34] |
| **email** | VARCHAR(100) | [cite_start]UNIQUE [cite: 34] |

### 6.3 Appointments Table
| Field Name | Data Type | Constraint / Core Purpose |
| :--- | :--- | :--- |
| **appointment_id** | INT | [cite_start]PRIMARY KEY, AUTO_INCREMENT [cite: 36] |
| **patient_id** | INT | [cite_start]FOREIGN KEY REFERENCES Patients(patient_id) [cite: 36] |
| **doctor_id** | INT | [cite_start]FOREIGN KEY REFERENCES Doctors(doctor_id) [cite: 36] |
| **appointment_date**| DATE | [cite_start]NOT NULL [cite: 36] |
| **appointment_time**| TIME | [cite_start]NOT NULL [cite: 36] |
| **status** | VARCHAR(20) | [cite_start]DEFAULT 'Scheduled' [cite: 36] |

### 6.4 Prescriptions Table
| Field Name | Data Type | Constraint / Core Purpose |
| :--- | :--- | :--- |
| **prescription_id**| INT | [cite_start]PRIMARY KEY, AUTO_INCREMENT [cite: 38] |
| **appointment_id** | INT | [cite_start]FOREIGN KEY REFERENCES Appointments(appointment_id) [cite: 38] |
| **medicine_name** | VARCHAR(100) | [cite_start]NOT NULL [cite: 38] |
| **dosage** | VARCHAR(50) | [cite_start]NOT NULL [cite: 38] |
| **instructions** | TEXT | [cite_start]OPTIONAL [cite: 38] |

### 6.5 Billing Table
| Field Name | Data Type | Constraint / Core Purpose |
| :--- | :--- | :--- |
| **bill_id** | INT | [cite_start]PRIMARY KEY, AUTO_INCREMENT [cite: 40] |
| **appointment_id** | INT | [cite_start]FOREIGN KEY REFERENCES Appointments(appointment_id) [cite: 40] |
| **total_amount** | DECIMAL(10,2)| [cite_start]NOT NULL [cite: 40] |
| **payment_status** | VARCHAR(20) | [cite_start]DEFAULT 'Unpaid' [cite: 40] |

---

## 7. Entity-Relationship (ER) Layout Overview
[cite_start]The schematic block diagram below illustrates the relational cardinality across the database workspace[cite: 42]:

```text
   +-------------+               +------------------+               +------------+
   |  Patients   |               |   Appointments   |               |  Doctors   |
   +-------------+               +------------------+               +------------+
   | patient_id  |1-----------* |  appointment_id  |  *-----------1| doctor_id  |
   +-------------+               |    patient_id    |               +------------+
                                 |    doctor_id     |
                                 +------------------+
                                        1      1
                                        |      |
                                        |      +------------------+
                                        * *
                                 +--------------+          +--------------+
                                 | Prescriptions|          |   Billing    |
                                 +--------------+          +--------------+
                                 |prescription_id          |   bill_id    |
                                 |appointment_id|          |appointment_id|
                                 +--------------+          +--------------+
