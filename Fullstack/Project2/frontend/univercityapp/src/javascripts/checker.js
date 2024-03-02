function PrintError(response) {
    var messages = {};
    for(var result in response) {
        messages[result] = (
            <div className="error">
                <ul style={{padding:0}}>
                    {response[result].map((num, index) => <li key={index}>{num}</li>)}
                    {console.log(response[result])}
                </ul>
            </div>
        )
    }
    return messages;
}

function FindError(object, response) {
    for(var obj in object) {
        var first = object[obj];
        var second = response[obj];
        if (typeof first === 'object') {
            first = JSON.stringify(first);
            second = JSON.stringify(second);
        }
        if(first !== second) {
            return false;
        }
    }
    return true;
}

export {FindError, PrintError};