using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UserData : MonoBehaviour {
    public static UserData instance;
    public string email { get; set; }
    public int score { get; set; }
    public float x { get; set; }
    public float y { get; set; }
    public float z { get; set; }

    public string getUserData() {
        return "email: " + email + " score: " + score.ToString() + " x: " + x.ToString() + " y: " + y.ToString() + " z: " + z.ToString(); 
    }
    private void Awake() {
        if(instance == null) {
            instance = this;
            DontDestroyOnLoad(this);
        }
    }
}
