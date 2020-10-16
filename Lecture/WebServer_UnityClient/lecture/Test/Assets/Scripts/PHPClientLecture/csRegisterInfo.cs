using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class csRegisterInfo : MonoBehaviour
{
    public InputField ifEmail;
    public InputField ifPassword;
    public Text txtResult;

    public void sendRegisterInfo() {
        StartCoroutine("coRegisterInfo");
    }

    IEnumerator coRegisterInfo() {
        string url = "http://127.0.0.1:12000/11_RegisterLoginInfo.php";
        string email = ifEmail.text;
        string password = ifPassword.text;

        // post
        WWWForm form = new WWWForm();
        form.AddField("email", email);
        form.AddField("password", password);
        UnityWebRequest request = new UnityWebRequest();
        using(request = UnityWebRequest.Post(url, form)) {
            yield return request.SendWebRequest();
            if(request.isNetworkError) {
                Debug.Log(request.error);
                txtResult.text = request.error;
            }
            else {
                Debug.Log("<post>" + request.downloadHandler.text + "</post>");
                string result = request.downloadHandler.text;
                Debug.Log($"result : {result}");
                if(result == "1") {
                    txtResult.text = "사용자가 등록되었습니다.";
                }
                else if(result=="0") {
                    txtResult.text = "이미 존재하는 사용자입니다.";
                }
                else if(result == "-1") {
                    txtResult.text = "Error";
                }
                else {
                    txtResult.text = "None";
                }
            }
        }
    }
    
}
