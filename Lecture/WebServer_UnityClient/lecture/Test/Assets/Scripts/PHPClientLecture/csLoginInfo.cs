using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class csLoginInfo : MonoBehaviour
{
    public InputField ifEmail;
    public InputField ifPassword;
    public Text txtResult;

    public void sendLoginInfo() {
        StartCoroutine("coLoginInfo");
    }

    IEnumerator coLoginInfo() {
        string url = "http://127.0.0.1:12000/13_LoginInfo.php";
        string email = ifEmail.text;
        string password = ifPassword.text;

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
                if(result == "2") {
                    Debug.Log("등록되지 않은 사용자입니다.");
                    txtResult.text = "등록되지 않은 사용자입니다.";
                }
                else if(result == "1") {
                    Debug.Log("password가 일치하지 않습니다.");
                    txtResult.text = "password가 일치하지 않습니다.";
                }
                else if(result == "0") {
                    Debug.Log("로그인 되었습니다.");
                    txtResult.text = "로그인 되었습니다.";
                }
                else if(result == "-1") {
                    Debug.Log("서버에서 DB접속 오류입니다.");
                    txtResult.text = "서버에서 DB접속 오류입니다.";
                }
            }
        }
    }
}
