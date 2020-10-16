using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class csChangeScene : MonoBehaviour
{
    public void ChangeScene() {
        SceneManager.LoadScene("PHPChangedScene");
    }
}
