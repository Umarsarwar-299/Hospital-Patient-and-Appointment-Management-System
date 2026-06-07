CREATE DATABASE HospitalDB;
USE HospitalDB;

-- Patients Table
CREATE TABLE Patients (
    patient_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    age INT,
    gender VARCHAR(10),
    phone VARCHAR(15),
    address TEXT
);

-- Doctors Table
CREATE TABLE Doctors (
    doctor_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    specialization VARCHAR(100),
    phone VARCHAR(15)
);

-- Doctor Schedules Table
CREATE TABLE Doctor_Schedules (
    schedule_id INT AUTO_INCREMENT PRIMARY KEY,
    doctor_id INT,
    available_date DATE,
    start_time TIME,
    end_time TIME,
    FOREIGN KEY (doctor_id) REFERENCES Doctors(doctor_id)
);

-- Appointments Table
CREATE TABLE Appointments (
    appointment_id INT AUTO_INCREMENT PRIMARY KEY,
    patient_id INT,
    doctor_id INT,
    appointment_date DATE,
    appointment_time TIME,
    status VARCHAR(20),
    FOREIGN KEY (patient_id) REFERENCES Patients(patient_id),
    FOREIGN KEY (doctor_id) REFERENCES Doctors(doctor_id)
);

-- Prescriptions Table
CREATE TABLE Prescriptions (
    prescription_id INT AUTO_INCREMENT PRIMARY KEY,
    appointment_id INT,
    medicines TEXT,
    notes TEXT,
    FOREIGN KEY (appointment_id) REFERENCES Appointments(appointment_id)
);

-- Billing Table
CREATE TABLE Billing (
    bill_id INT AUTO_INCREMENT PRIMARY KEY,
    appointment_id INT,
    amount DECIMAL(10,2),
    payment_status VARCHAR(20),
    FOREIGN KEY (appointment_id) REFERENCES Appointments(appointment_id)
);

-- Stored Procedure for Appointment Conflict Checking
DELIMITER $$

CREATE PROCEDURE BookAppointment(
    IN p_patient_id INT,
    IN p_doctor_id INT,
    IN p_date DATE,
    IN p_time TIME
)
BEGIN
    DECLARE conflict_count INT;

    SELECT COUNT(*) INTO conflict_count
    FROM Appointments
    WHERE doctor_id = p_doctor_id
    AND appointment_date = p_date
    AND appointment_time = p_time;

    IF conflict_count > 0 THEN
        SELECT 'Error: Appointment slot already booked!' AS Message;
    ELSE
        INSERT INTO Appointments(patient_id, doctor_id, appointment_date, appointment_time, status)
        VALUES(p_patient_id, p_doctor_id, p_date, p_time, 'Scheduled');

        SELECT 'Appointment Booked Successfully!' AS Message;
    END IF;
END$$

DELIMITER ;

-- Trigger for Auto Billing
DELIMITER $$

CREATE TRIGGER GenerateBill
AFTER INSERT ON Appointments
FOR EACH ROW
BEGIN
    INSERT INTO Billing(appointment_id, amount, payment_status)
    VALUES(NEW.appointment_id, 1000.00, 'Pending');
END$$

DELIMITER ;

-- Sample Data
INSERT INTO Patients(name, age, gender, phone, address)
VALUES
('Ali Khan', 25, 'Male', '03001234567', 'Karachi'),
('Sara Ahmed', 30, 'Female', '03111234567', 'Lahore');

INSERT INTO Doctors(name, specialization, phone)
VALUES
('Dr. Hassan', 'Cardiologist', '03211234567'),
('Dr. Fatima', 'Dermatologist', '03331234567');

INSERT INTO Doctor_Schedules(doctor_id, available_date, start_time, end_time)
VALUES
(1, '2026-05-10', '09:00:00', '13:00:00'),
(2, '2026-05-10', '10:00:00', '14:00:00');

-- Test Appointment Booking
CALL BookAppointment(1, 1, '2026-05-10', '10:00:00');

-- View Data
SELECT * FROM Patients;
SELECT * FROM Doctors;
SELECT * FROM Appointments;
SELECT * FROM Billing;