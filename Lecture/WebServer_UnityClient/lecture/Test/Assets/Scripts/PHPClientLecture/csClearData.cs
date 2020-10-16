using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class csClearData : MonoBehaviour
{
    public InputField ifEmail;
    public InputField ifScore;
    public InputField ifx;
    public InputField ify;
    public InputField ifz;
    public Text txtResult;

    public void clearData() {
        ifEmail.text = "";
        ifScore.text = "";
        ifx.text = "";
        ify.text = "";
        ifz.text = "";
        txtResult.text = "";
    }
}
