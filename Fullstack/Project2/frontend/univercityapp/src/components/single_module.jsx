function SingleModule({ module, setComponent }) {
    const ShowModule = () => {
        return (
            <div>
                <h1 style={{ marginBottom: "20px" }}>{module.full_name}</h1>
                <h5>Code: {module.code}</h5>
                <h5>CA Percentage: {module.ca_split}%</h5>
            </div>
        )
    }

    return (
        <div>
            {ShowModule()}
        </div>
    )
}
export default SingleModule;