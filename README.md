# Hospital-Patient-and-Appointment-Management-System
<!DOCTYPE html>
<html>
<head>
    <title>Hospital Patient and Appointment Management System</title>
</head>
<body>

    <h1>Hospital Patient and Appointment Management System</h1>

    <h2>1. Introduction</h2>
    <p>
        The Hospital Patient and Appointment Management System is a database project designed
        to manage hospital operations efficiently. The system stores patient records,
        doctor details, schedules, appointments, prescriptions, and billing information.
    </p>

    <h2>2. Objectives</h2>
    <ul>
        <li>Digital Records Management</li>
        <li>Staff Tracking</li>
        <li>Automated Workflows</li>
        <li>Data Integrity</li>
        <li>Practical Application</li>
    </ul>

    <h2>3. Problem Statement</h2>
    <p>
        Traditional paper-based hospital systems create appointment conflicts,
        billing delays, and data redundancy. This project solves these issues
        using a relational database system.
    </p>

    <h2>4. System Features</h2>
    <ul>
        <li>Patient Profiles</li>
        <li>Doctor Roster Scheduling</li>
        <li>Smart Scheduling</li>
        <li>Automated Ledger Invoicing</li>
        <li>Medical Prescription Ledger</li>
    </ul>

    <h2>5. Tools and Technologies Used</h2>

    <table border="1" cellpadding="5">
        <tr>
            <th>Technology Category</th>
            <th>Specification</th>
        </tr>
        <tr>
            <td>RDBMS Engine</td>
            <td>MySQL Server 8.0+</td>
        </tr>
        <tr>
            <td>IDE</td>
            <td>MySQL Workbench</td>
        </tr>
        <tr>
            <td>Query Language</td>
            <td>SQL</td>
        </tr>
    </table>

    <h2>6. Database Design</h2>

    <h3>Patients Table</h3>
    <table border="1" cellpadding="5">
        <tr>
            <th>Field Name</th>
            <th>Data Type</th>
            <th>Constraint</th>
        </tr>
        <tr>
            <td>patient_id</td>
            <td>INT</td>
            <td>PRIMARY KEY</td>
        </tr>
        <tr>
            <td>name</td>
            <td>VARCHAR(100)</td>
            <td>NOT NULL</td>
        </tr>
        <tr>
            <td>age</td>
            <td>INT</td>
            <td>NOT NULL</td>
        </tr>
    </table>

    <h3>Doctors Table</h3>
    <table border="1" cellpadding="5">
        <tr>
            <th>Field Name</th>
            <th>Data Type</th>
            <th>Constraint</th>
        </tr>
        <tr>
            <td>doctor_id</td>
            <td>INT</td>
            <td>PRIMARY KEY</td>
        </tr>
        <tr>
            <td>name</td>
            <td>VARCHAR(100)</td>
            <td>NOT NULL</td>
        </tr>
        <tr>
            <td>specialization</td>
            <td>VARCHAR(100)</td>
            <td>NOT NULL</td>
        </tr>
    </table>

    <h2>7. ER Diagram Overview</h2>

    <pre>
Patients ----< Appointments >---- Doctors
                    |
                    |
             ----------------
             |              |
       Prescriptions      Billing
    </pre>

    <h2>8. SQL Script</h2>

    <pre>
CREATE DATABASE HospitalManagement;
USE HospitalManagement;

CREATE TABLE Patients (
    patient_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT NOT NULL,
    gender VARCHAR(10) NOT NULL
);
    </pre>

    <h2>9. Stored Procedure</h2>

    <pre>
DELIMITER //

CREATE PROCEDURE BookAppointment(
    IN p_id INT,
    IN d_id INT
)
BEGIN
    INSERT INTO Appointments(patient_id, doctor_id)
    VALUES(p_id, d_id);
END //

DELIMITER ;
    </pre>

    <h2>10. Trigger</h2>

    <pre>
DELIMITER //

CREATE TRIGGER GenerateBill
AFTER INSERT ON Appointments
FOR EACH ROW
BEGIN
    INSERT INTO Billing(appointment_id, total_amount)
    VALUES(NEW.appointment_id, 50.00);
END //

DELIMITER ;
    </pre>

    <h2>11. Sample Data</h2>

    <pre>
INSERT INTO Patients(name, age, gender)
VALUES ('Ali Khan', 34, 'Male');

INSERT INTO Doctors(name, specialization)
VALUES ('Dr. Shahzad', 'Cardiologist');
    </pre>

    <h2>12. Reporting Queries</h2>

    <pre>
SELECT * FROM Patients;

SELECT * FROM Doctors;

SELECT * FROM Appointments;
    </pre>

    <h2>13. Advantages</h2>
    <ul>
        <li>Reduces paperwork</li>
        <li>Fast appointment management</li>
        <li>Automatic bill generation</li>
        <li>Improves hospital efficiency</li>
    </ul>

    <h2>14. Limitations</h2>
    <ul>
        <li>No GUI support</li>
        <li>Basic security</li>
        <li>No online payment integration</li>
    </ul>

    <h2>15. Future Enhancements</h2>
    <ul>
        <li>Web-based interface</li>
        <li>SMS and Email notifications</li>
        <li>Online billing system</li>
    </ul>

    <h2>16. Conclusion</h2>
    <p>
        The Hospital Patient and Appointment Management System provides
        an efficient and reliable solution for handling hospital data
        using MySQL database technologies.
    </p>

    <h2>17. References</h2>
    <ul>
        <li>MySQL Documentation</li>
        <li>Database System Concepts Book</li>
        <li>MySQL Workbench Guide</li>
    </ul>

</body>
</html>
