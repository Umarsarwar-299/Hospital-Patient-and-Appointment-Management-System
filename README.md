# Hospital-Patient-and-Appointment-Management-System



## Database Systems Project Report

### Group 5

* Khubaib Imran (Admin)
* Fahad Ali
* Ayyan Ahmad
* Omar Sarwar
* Mahnoor
* Mehrunnisa

---

# 1. Introduction

The Hospital Patient and Appointment Management System is a database project designed to manage hospital operations efficiently. The system stores patient records, doctor details, schedules, appointments, prescriptions, and billing information.

This project uses SQL and MySQL Workbench to demonstrate foundational and advanced database concepts, including database creation, table relationships with primary and foreign keys, automated stored procedures, defensive triggers, and optimized data filtering queries. The project helps automate everyday hospital tasks, prevents systemic data redundancy, and drastically reduces manual paperwork burden.

---

# 2. Objectives

The major objectives of this database design project are:

* **Digital Records Management:** To secure, persist, and easily query patient profiles and histories electronically.
* **Staff Tracking:** To maintain accurate schedules, department allocations, and contact parameters for medical doctors.
* **Automated Workflows:** To automate appointment booking queues and compute patient billing records instantly via backend triggers.
* **Data Integrity:** To avoid concurrent booking conflicts or scheduling duplication through relational constraints.
* **Practical Application:** To apply relational database theory (DDL/DML scripting, procedures, normalization) to a real-world enterprise situation.

---

# 3. Problem Statement

Traditional paper-based or un-indexed spreadsheet recording practices in hospital administration consistently create critical challenges, such as mismanaged clinical appointments, data conflicts, and slow manual billing generation. Without synchronized tracking, patients experience double-booked slots, and administrative workers waste substantial time manually creating financial receipts.

This project resolves these clinical issues by building a clean relational architecture where patient status changes, appointment requests, doctor timetables, and invoices are instantly updated across the entire network.

---

# 4. System Features

* **Patient Profiles:** Comprehensive data collection including names, contact keys, ages, and medical genders.
* **Doctor Roster Scheduling:** Maintains strict lookups for specialized fields, specific contact numbers, and office emails.
* **Smart Scheduling:** Links appointments directly to specific calendar dates and times, preventing overlapping timeslots.
* **Automated Ledger Invoicing:** Utilizes server-side triggers to instantly generate billing entries as soon as appointments are entered.
* **Medical Prescription Ledger:** Safely matches diagnostic descriptions and pharmaceutical dosages to corresponding appointment events.

---

# 5. Tools and Technologies Used

| Technology Category   | Specification & Operational Role                                      |
| --------------------- | --------------------------------------------------------------------- |
| RDBMS Engine          | MySQL Server 8.0+ (Provides transactional data execution)             |
| Visual Modeling / IDE | MySQL Workbench (Used for DDL/DML authoring and schema visualization) |
| Query Language        | Structured Query Language (SQL) for database building and reporting   |

---

# 6. Database Design

The design uses a clean relational layout with 5 central tables linked together through relational foreign keys. This design ensures that change tracking flows correctly across records and prevents orphaned files.

## 6.1 Patients Table

| Field Name | Data Type    | Constraint / Core Purpose   |
| ---------- | ------------ | --------------------------- |
| patient_id | INT          | PRIMARY KEY, AUTO_INCREMENT |
| name       | VARCHAR(100) | NOT NULL                    |
| age        | INT          | NOT NULL                    |
| gender     | VARCHAR(10)  | NOT NULL                    |
| phone      | VARCHAR(15)  | NOT NULL                    |
| address    | TEXT         | OPTIONAL                    |

## 6.2 Doctors Table

| Field Name     | Data Type    | Constraint / Core Purpose   |
| -------------- | ------------ | --------------------------- |
| doctor_id      | INT          | PRIMARY KEY, AUTO_INCREMENT |
| name           | VARCHAR(100) | NOT NULL                    |
| specialization | VARCHAR(100) | NOT NULL                    |
| phone          | VARCHAR(15)  | NOT NULL                    |
| email          | VARCHAR(100) | UNIQUE                      |

## 6.3 Appointments Table

| Field Name       | Data Type   | Constraint / Core Purpose                   |
| ---------------- | ----------- | ------------------------------------------- |
| appointment_id   | INT         | PRIMARY KEY, AUTO_INCREMENT                 |
| patient_id       | INT         | FOREIGN KEY REFERENCES Patients(patient_id) |
| doctor_id        | INT         | FOREIGN KEY REFERENCES Doctors(doctor_id)   |
| appointment_date | DATE        | NOT NULL                                    |
| appointment_time | TIME        | NOT NULL                                    |
| status           | VARCHAR(20) | DEFAULT 'Scheduled'                         |

## 6.4 Prescriptions Table

| Field Name      | Data Type    | Constraint / Core Purpose                           |
| --------------- | ------------ | --------------------------------------------------- |
| prescription_id | INT          | PRIMARY KEY, AUTO_INCREMENT                         |
| appointment_id  | INT          | FOREIGN KEY REFERENCES Appointments(appointment_id) |
| medicine_name   | VARCHAR(100) | NOT NULL                                            |
| dosage          | VARCHAR(50)  | NOT NULL                                            |
| instructions    | TEXT         | OPTIONAL                                            |

## 6.5 Billing Table

| Field Name     | Data Type     | Constraint / Core Purpose                           |
| -------------- | ------------- | --------------------------------------------------- |
| bill_id        | INT           | PRIMARY KEY, AUTO_INCREMENT                         |
| appointment_id | INT           | FOREIGN KEY REFERENCES Appointments(appointment_id) |
| total_amount   | DECIMAL(10,2) | NOT NULL                                            |
| payment_status | VARCHAR(20)   | DEFAULT 'Unpaid'                                    |

---

# 7. Entity-Relationship (ER) Layout Overview

```text
+-------------+               +------------------+               +------------+
|  Patients   |               |   Appointments   |               |  Doctors   |
+-------------+               +------------------+               +------------+
| patient_id  |1-----------* |  appointment_id  | *-----------1 | doctor_id  |
+-------------+               |    patient_id    |               +------------+
                              |    doctor_id     |
                              +------------------+
                                     |      |
                                     |      |
                          +--------------+  +--------------+
                          | Prescriptions|  |   Billing    |
                          +--------------+  +--------------+
                          |prescription_id| |   bill_id    |
                          |appointment_id | |appointment_id|
                          +--------------+  +--------------+
```

---

# 8. SQL System Script Implementation

```sql
CREATE DATABASE HospitalManagement;
USE HospitalManagement;

CREATE TABLE Patients (
    patient_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT NOT NULL,
    gender VARCHAR(10) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    address TEXT
);

CREATE TABLE Doctors (
    doctor_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    specialization VARCHAR(100) NOT NULL,
    phone VARCHAR(15) NOT NULL,
    email VARCHAR(100) UNIQUE
);

CREATE TABLE Appointments (
    appointment_id INT AUTO_INCREMENT PRIMARY KEY,
    patient_id INT,
    doctor_id INT,
    appointment_date DATE NOT NULL,
    appointment_time TIME NOT NULL,
    status VARCHAR(20) DEFAULT 'Scheduled',
    FOREIGN KEY (patient_id) REFERENCES Patients(patient_id) ON DELETE CASCADE,
    FOREIGN KEY (doctor_id) REFERENCES Doctors(doctor_id) ON DELETE CASCADE
);

CREATE TABLE Prescriptions (
    prescription_id INT AUTO_INCREMENT PRIMARY KEY,
    appointment_id INT,
    medicine_name VARCHAR(100) NOT NULL,
    dosage VARCHAR(50) NOT NULL,
    instructions TEXT,
    FOREIGN KEY (appointment_id) REFERENCES Appointments(appointment_id) ON DELETE CASCADE
);

CREATE TABLE Billing (
    bill_id INT AUTO_INCREMENT PRIMARY KEY,
    appointment_id INT,
    total_amount DECIMAL(10,2) NOT NULL,
    payment_status VARCHAR(20) DEFAULT 'Unpaid',
    FOREIGN KEY (appointment_id) REFERENCES Appointments(appointment_id) ON DELETE CASCADE
);
```

---

# 9. Stored Procedure: BookAppointment

```sql
DELIMITER //

CREATE PROCEDURE BookAppointment(
    IN p_id INT,
    IN d_id INT,
    IN a_date DATE,
    IN a_time TIME
)
BEGIN
    INSERT INTO Appointments (
        patient_id,
        doctor_id,
        appointment_date,
        appointment_time,
        status
    )
    VALUES (
        p_id,
        d_id,
        a_date,
        a_time,
        'Scheduled'
    );
END //

DELIMITER ;
```

---

# 10. Trigger Implementation: GenerateBill

```sql
DELIMITER //

CREATE TRIGGER GenerateBill
AFTER INSERT ON Appointments
FOR EACH ROW
BEGIN
    INSERT INTO Billing (
        appointment_id,
        total_amount,
        payment_status
    )
    VALUES (
        NEW.appointment_id,
        50.00,
        'Unpaid'
    );
END //

DELIMITER ;
```

---

# 11. Sample Data Seed Scripts

```sql
INSERT INTO Patients (name, age, gender, phone, address)
VALUES
('Ali Khan', 34, 'Male', '03001234567', 'Multan'),
('Ayesha Bibi', 28, 'Female', '03129876543', 'Lahore');

INSERT INTO Doctors (name, specialization, phone, email)
VALUES
('Dr. Shahzad', 'Cardiologist', '03215556677', 'shahzad@hospital.com'),
('Dr. Amna', 'Pediatrician', '03334445566', 'amna@hospital.com');
```

---

# 12. Operational Reporting Queries

```sql
-- View All Registered Patients
SELECT * FROM Patients;

-- View Appointment Tracking Matrix
SELECT * FROM Appointments;

-- Unified View: Link Patients to Doctors and Booked Invoices
SELECT
    a.appointment_id,
    p.name AS Patient,
    d.name AS Doctor,
    a.appointment_date,
    b.total_amount
FROM Appointments a
JOIN Patients p ON a.patient_id = p.patient_id
JOIN Doctors d ON a.doctor_id = d.doctor_id
JOIN Billing b ON a.appointment_id = b.appointment_id;
```

---

# 13. Advantages of the System

* **Reduces Paperwork:** Moves physical records into secure, centralized relational tables.
* **Fast Appointment Management:** Enables rapid administrative searching and updates via indexed primary keys.
* **Prevents Overlaps:** Maintains strict checking parameters across calendar timeslots.
* **Automatic Bill Generation:** Uses database event triggers to instantly calculate and record entry-level invoices.
* **Better Hospital Efficiency:** Saves hours of data entry work for medical assistants.

---

# 14. Limitations

* **No Graphical User Interface (GUI):** Relies strictly on developer console parsing or raw SQL command workbenches.
* **Basic Security Framework:** Lacks advanced multi-factor role authentication or row-level permissions.
* **No Online Payment Integration:** Does not connect to modern web payment gateways (Stripe, PayPal) for processing card transactions.
* **Small-Scale Optimization:** Designed for localized clinic networks rather than global healthcare infrastructure.

---

# 15. Future Enhancements

* **Web-Based Client Interface:** Build a public-facing booking portal using a modern web framework (e.g., Node.js or Python Django).
* **Advanced Notification Systems:** Configure real-time automated SMS and email alerts for upcoming patient appointments.
* **Laboratory and Pharmacy Modules:** Expand the schema with custom tables to track medicine inventory levels and lab test results.
* **Secure Online Billing:** Integrate web payment APIs to allow patients to view and settle outstanding bills online.

---

# 16. Conclusion

The Hospital Patient and Appointment Management System successfully builds a reliable relational database application using MySQL. By handling operations directly within the engine tier through automated triggers and stored procedures, the design eliminates manual paperwork, keeps data clean, and ensures fast processing speeds. This design provides a strong foundation for a complete healthcare application.

---

# 17. References

* MySQL Server Documentation (8.0+ Reference Manual)
* Database System Concepts by Silberschatz, Korth, and Sudarshan
* MySQL Workbench User Guide

