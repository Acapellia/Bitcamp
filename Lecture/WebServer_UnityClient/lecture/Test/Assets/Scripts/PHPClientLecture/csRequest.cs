using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.UI;

public class csRequest : MonoBehaviour
{
    public InputField inputA;
    public InputField inputB;
    public InputField inputResult;

    public void RequestGet() {
        StartCoroutine("coGet");
    }
    public void RequestPost() {
        StartCoroutine("coPost");
    }

    IEnumerator coGet() {
        //string url = "http://acapellia.dothome.co.kr/07_request_response.php?";
        string url = "http://127.0.0.1:12000/07_request_response.php?";
        string a = inputA.text;
        string b = inputB.text;
        url += string.Format($"a={a}");
        url += "&";
        url += string.Format($"b={b}");
        UnityWebRequest request = new UnityWebRequest();
        using(request = UnityWebRequest.Get(url)) {
            yield return request.SendWebRequest();
            if(request.isNetworkError) {
                Debug.Log(request.error);
            }
            else {
                Debug.Log("<get>" + request.downloadHandler.text + "</get>");
                inputResult.text = request.downloadHandler.text;
            }
        }
    }

    IEnumerator coPost() {
        //string url = "http://acapellia.dothome.co.kr/07_request_response.php";
        string url = "http://127.0.0.1:12000/09_dbtest.php";
        string a = inputA.text;
        string b = inputB.text;
        WWWForm form = new WWWForm();
        form.AddField("a", a);
        form.AddField("b", b);
        UnityWebRequest request = new UnityWebRequest();
        using(request = UnityWebRequest.Post(url, form)) {
            yield return request.SendWebRequest();
            if(request.isNetworkError) {
                Debug.Log(request.error);
            }
            else {
                Debug.Log("<post>" + request.downloadHandler.text + "</post>");
                inputResult.text = request.downloadHandler.text;
            }
        }

    }
}
