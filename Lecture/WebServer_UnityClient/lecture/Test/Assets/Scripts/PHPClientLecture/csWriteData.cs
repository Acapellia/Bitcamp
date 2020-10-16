using Boomlagoon.JSON;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class csWriteData : MonoBehaviour
{
    public InputField ifEmail;
    public InputField ifScore;
    public InputField ifx;
    public InputField ify;
    public InputField ifz;
    public Text txtResult;

    public void writeData() {
        StartCoroutine("coWriteData");
    }

    IEnumerator coWriteData() {
        string url = "http://127.0.0.1:12000/14_WriteRead.php";
        string email = ifEmail.text;
        string score = ifScore.text;
        string x = ifx.text;
        string y = ify.text;
        string z = ifz.text;

        WWWForm form = new WWWForm();
        form.AddField("iswrite", "1");
        form.AddField("email",email);
        form.AddField("score",score);
        form.AddField("x",x);
        form.AddField("y",y);
        form.AddField("z",z);

        UnityWebRequest request = new UnityWebRequest();
        using(request = UnityWebRequest.Post(url, form)) {
            yield return request.SendWebRequest();

            if(request.isNetworkError) {
                Debug.Log(request.error);
                txtResult.text = request.error;
            }
            else {
                Debug.Log("<post>" + request.downloadHandler.text + "</post>");
                JSONObject json = JSONObject.Parse(request.downloadHandler.text);
                string result = json.GetString("result");
                switch(result) {
                    case "update":
                        txtResult.text = "기존 데이터 변경"; break;
                    case "insert":
                        txtResult.text = "새로 데이터 추가"; break;
                    default:
                        txtResult.text = "error : " + json.GetString("error"); break;
                }
                
            }
        }
    }
}
