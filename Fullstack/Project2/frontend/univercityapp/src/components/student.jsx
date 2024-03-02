import SingleStudent from "./single_student";
import AddStudent from "./add_student";

function Student({ setComponent }) {
    const findStudent = (info) => {
        info.preventDefault();
        var student_id = document.getElementById("student_id").value;
        fetch("http://127.0.0.1:8000/api/student/" + student_id + "/")
            .then(response => response.json())
            .then(data => {
                if (data.detail !== "Not found.") {
                    setComponent(<SingleStudent student={data} setComponent={setComponent} />);
                }
                else {
                    alert("Student not found");
                }
            })
            .catch(error => { console.log(error); })
    }

    return (
        <div>
            <div style={{ display: "flex", justifyContent: "center", marginTop: "12px" }}>
                <form onSubmit={findStudent} style={{ display: "flex", alignItems: "baseline" }}>
                    <label htmlFor="student_id" className="form-label text-center"><h5>Enter Student ID:</h5></label>
                    <input type="Text" id="student_id" className="form-control" style={{ width: "150px", margin: "0 10px" }} required />
                    <button type="submit" className="btn btn-dark">SUBMIT</button>
                </form>
            </div>
            <br />
            <div>
                <button type="button" className="btn btn-dark" onClick={() => {setComponent(<AddStudent setComponent={setComponent} />)}}>
                    ADD STUDENT
                </button>
            </div>
        </div>
    )
}
export default Student;