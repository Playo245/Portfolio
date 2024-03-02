import Degree from '../images/degree.png';
import Module from '../images/module.png';
import Cohurts from '../images/cohurts.png';
import StudentImg from '../images/student.png';
import AllCohort from "./all_cohort";
import Student from "./student";
import AllDegree from "./all_degree";
import AllModule from "./all_module";

function Homepage({ setComponent }) {
    return (
        <div className="container text-center" style={{ paddingTop: "35px" }}>
            <h1 style={{ fontSize: "46px", marginTop: "12px" }}>Welcome to Freedom University Registration!</h1>
            <div className="row" style={{ marginTop: "45px" }}>
                <div className="card w-50 card-body mb-4">
                    <button type="button" onClick={() => { setComponent(<AllDegree setComponent={setComponent} />) }}>
                        <img src={Degree} alt="Logo" width="50" height="50" />{/*Source: https://freeicons.io/material-icons-social-2/school-icon-16801*/}
                        <h4>Degrees</h4>
                    </button>
                </div>
                <div className="card w-50 card-body mb-4">
                    <button type="button" onClick={() => { setComponent(<AllModule setComponent={setComponent} />) }}>
                        <img src={Module} alt="module" width="50" height="50" />{/*Source: https://freeicons.io/education-and-learning/education-and-learning-book-learn-school-library-bookmark-icon-42449*/}
                        <h4>Modules</h4>
                    </button>
                </div>
                <div className="card w-50 card-body mb-4">
                    <button type="button" onClick={() => { setComponent(<AllCohort setComponent={setComponent} />) }}>
                        <img src={Cohurts} alt="cohurts" width="50" height="50" />{/*Source: https://freeicons.io/uniform-outfit-clothing-icon-set/attire-boy-clothing-girl-school-student-uniform-icon-59371*/}
                        <h4>Cohorts</h4>
                    </button>
                </div>
                <div className="card w-50 card-body mb-4">
                    <button type="button" onClick={() => { setComponent(<Student setComponent={setComponent} />) }}>
                        <img src={StudentImg} alt="student" width="50" height="50" />{/*Source: https://freeicons.io/school-events-sessions-icon-set/child-graduate-graduation-junior-school-student-success-icon-61859*/}
                        <h4>Students</h4>
                    </button>
                </div>
            </div>
        </div>
    )
}
export default Homepage;