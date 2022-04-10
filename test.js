var prompt = "prompt place holder"
var name1 = "name1 place holder"
var name2 = "name2 place holder"
var url1 = "https://via.placeholder.com/100"
var url2 = "https://via.placeholder.com/100"
        
function updatevalues(prompt, name1, name2, url1, url2) {
    document.getElementById("prompt").innerHTML = prompt
    document.getElementById("name1").innerHTML = name1
    document.getElementById("name2").innerHTML = name2
    document.getElementById("img1").src = url1
    document.getElementById("img2").src = url2
}
        
updatevalues(prompt, name1, name2, url1, url2)
        
function callapi() {
            
    var url = 'http://198.166.111.139:2269/getcurrent/'+email+'/'+pw
            
    $.ajax ({
        url:url,
        success:function(result) {
            data = result
                    
            prompt = data["prompt"]
            name1 = data["name1"]
            name2 = data["name2"]
            url1 = data["url1"]
            url2 = data["url2"]
                    
            updatevalues(prompt, name1, name2, url1, url2)
        }
    })            
            
}

function vote(choice) {
    console.log(pw)
            
    if (choice == 1) {
        var url = 'http://198.166.111.139:2269/vote/'+email+'/'+pw+'/'+name1+'/'+name2
                
        $.ajax ({
            url:url,
            success:function(result){callapi()}
        })
    } 
    else {
        var url = 'http://198.166.111.139:2269/vote/'+email+'/'+pw+'/'+name2+'/'+name1
                
        $.ajax ({
            url:url,
            success:function(result){callapi()}
        })
    }
}
  
function sendresetemail() {
    var url = 'http://198.166.111.139:2269/reset/'+email

    $.ajax ({
        url:url,
        success:function(result){
            data = result
            time = data['time']
            var es = document.getElementById('emailsent')
            es.innerHTML = 'Success (check inbox)<br><br>Email sent at '+time
        }
    })             
}
        
function checkpw() {
    pw = document.getElementById('pwfield').value
            
    var url = 'http://198.166.111.139:2269/checkpw/' + email + '/' + pw
            
    $.ajax ({
        url:url,
        success:function(result){
            data = result
            responce = data['responce']
                    
            if (responce == 'False') {
                var es = document.getElementById('emailsent')
                es.innerHTML = 'Invalid password<br>Please try again'
            }
            else {
                document.getElementById("block").style.display = "none"
                document.getElementById("pw").style.display = "none"
                document.getElementById("vote").style.display = "block"
                callapi()
            }
        }
    })
}

email = sessionStorage.getItem('email')
        
if (email !== null) {
    document.getElementById("block").style.display = "none"
    document.getElementById("pw").style.display = "block"
    document.getElementById("vote").style.display = "none"
            
    var pwforemail = document.getElementById("pwforemail")
    pwforemail.innerHTML = 'Please enter your password for the email ' + email
            
}
else {
    document.getElementById("block").style.display = "block"
    document.getElementById("pw").style.display = "none"
    document.getElementById("vote").style.display = "none"  
}