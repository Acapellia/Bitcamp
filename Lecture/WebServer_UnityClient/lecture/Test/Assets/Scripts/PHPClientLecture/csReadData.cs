using Boomlagoon.JSON;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class csReadData : MonoBehaviour
{
    public InputField ifEmail;
    public InputField ifScore;
    public InputField ifx;
    public InputField ify;
    public InputField ifz;
    public Text txtResult;

    public void readData() {
        StartCoroutine("coReadData");
    }

    IEnumerator coReadData() {
        string url = "http://127.0.0.1:12000/14_WriteRead.php";
        string email = ifEmail.text;


        WWWForm form = new WWWForm();
        form.AddField("iswrite", "0");
        form.AddField("email", email);

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
                    case "read":
                        txtResult.text = "데이터 읽어옴";
                        ifScore.text = json.GetNumber("score").ToString();
                        ifx.text = json.GetNumber("x").ToString();
                        ify.text = json.GetNumber("y").ToString(); 
                        ifz.text = json.GetNumber("z").ToString();

                        UserData.instance.email = email;
                        UserData.instance.score = (int)json.GetNumber("score");
                        UserData.instance.x = (float)json.GetNumber("x");
                        UserData.instance.y = (float)json.GetNumber("y");
                        UserData.instance.z = (float)json.GetNumber("z");
                        break;
                    case "noread":
                        txtResult.text = "데이터 존재하지 않음";
                        ifScore.text = "";
                        ifx.text = "";
                        ify.text = "";
                        ifz.text = "";
                        break;
                }

            }
        }
    }
}
