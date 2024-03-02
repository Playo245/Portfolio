import { useState } from "react";
import SingleStudent from "./single_student";
import { FindError, PrintError } from "../javascripts/checker";

function AddGrade({ setComponent, grade_id, student, module, cohort }) {
    const [error, setError] = useState([""]);

    const ShowForm = () => {
        return (
            <form id="gradeForm" onSubmit={validator} method="POST">
                <label htmlFor="ca_mark" className="form-label">CA mark:</label>
                <input type="Text" id="ca_mark" className="form-control" />
                {error.ca_mark}
                <label htmlFor="exam_mark" className="form-label">Exam mark:</label>
                <input type="Text" id="exam_mark" className="form-control" />
                {error.exam_mark}
                <button type="submit" className="btn btn-dark view-button">Submit</button>
            </form>
        )
    }

    const validateMarks = () => {
        const caMarkInput = document.getElementById("ca_mark");
        const examMarkInput = document.getElementById("exam_mark");
        
        const caMark = parseFloat(caMarkInput.value);
        const examMark = parseFloat(examMarkInput.value);
        
        const errors = {};
        
        if (isNaN(caMark) || caMark < 0) {
            errors.ca_mark = "CA mark must be a non-negative number.";
        }
        
        if (isNaN(examMark) || examMark < 0) {
            errors.exam_mark = "Exam mark must be a non-negative number.";
        }
        
        if (Object.keys(errors).length > 0) {
            setError(errors);
            return false;
        }
        
        return true;
    };

    const validator = async (e) => {
        e.preventDefault();
        if (validateMarks()) {
            let gradeForm = document.getElementById("gradeForm");
            var grade = {
                "module": module,
                "ca_mark": parseInt(gradeForm.ca_mark.value),
                "exam_mark": parseInt(gradeForm.exam_mark.value),
                "cohort": cohort,
                "student": "http://127.0.0.1:8000/api/student/" + student.student_id + "/",
            };
      
            try {
                const response = await fetch(
                    "http://127.0.0.1:8000/api/grade/" + grade_id + "/",
                    {
                        method: "PUT",
                        headers: {
                            "Content-Type": "application/json",
                        },
                        body: JSON.stringify(grade),
                    }
                );
                const data = await response.json();
                console.log("Success:", data);
                if (!FindError(grade, data)) {
                    setError(PrintError(data));
                } else {
                    setComponent(<SingleStudent setComponent={setComponent} student={student} />);
                }
            } catch (error) {
                console.log(error);
            }
        }
    };

    return (
        <div className="form-page">
            {ShowForm()}
        </div>
    )
}
export default AddGrade;