using Boomlagoon.JSON;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;

public class csRecordReplay : MonoBehaviour
{
    enum OBJ_STATE
    {
        NOSTATE,
        RECORD,
        REPLAY
    }

    public Transform cube;
    public int cubeId = 1;
    public float delayTime = 0.1f;
    OBJ_STATE objState = OBJ_STATE.NOSTATE;

    public void StartRecord()
    {
        objState = OBJ_STATE.RECORD;
        StartCoroutine(coRecord());
    }
    IEnumerator coRecord()
    {
        while (objState == OBJ_STATE.RECORD)
        {
            string url = "http://localhost:12000/16_recordMoveRotate.php";
            string position_x = cube.position.x.ToString();
            string position_y = cube.position.y.ToString();
            string position_z = cube.position.z.ToString();
            string rotation_x = cube.rotation.x.ToString();
            string rotation_y = cube.rotation.y.ToString();
            string rotation_z = cube.rotation.z.ToString();
            string rotation_w = cube.rotation.w.ToString();
            string scale_x = cube.localScale.x.ToString();
            string scale_y = cube.localScale.y.ToString();
            string scale_z = cube.localScale.z.ToString();

            WWWForm form = new WWWForm();
            form.AddField("isrecord", "1");
            form.AddField("obj_id", cubeId);
            form.AddField("position_x", position_x);
            form.AddField("position_y", position_y);
            form.AddField("position_z", position_z);
            form.AddField("rotation_x", rotation_x);
            form.AddField("rotation_y", rotation_y);
            form.AddField("rotation_z", rotation_z);
            form.AddField("rotation_w", rotation_w);
            form.AddField("scale_x", scale_x);
            form.AddField("scale_y", scale_y);
            form.AddField("scale_z", scale_z);

            UnityWebRequest request = new UnityWebRequest();

            using (request = UnityWebRequest.Post(url, form))
            {
                yield return request.SendWebRequest();

                if (request.isNetworkError)
                    Debug.Log(request.error);
                else
                    Debug.Log("<post>" + request.downloadHandler.text + "</post>");
            }

            //yield return new WaitForSeconds(delayTime);
        }
    }
    public void StartReplay()
    {
        objState = OBJ_STATE.REPLAY;
        StartCoroutine(coReplay());
    }
    IEnumerator coReplay()
    {
        string url = "http://localhost:12000/16_recordMoveRotate.php";

        WWWForm form = new WWWForm();
        form.AddField("isrecord", "0");
        form.AddField("obj_id", cubeId);

        UnityWebRequest request = new UnityWebRequest();

        using (request = UnityWebRequest.Post(url, form))
        {
            yield return request.SendWebRequest();

            if (request.isNetworkError)
                Debug.Log(request.error);
            else
            {
                Debug.Log("<post>" + request.downloadHandler.text + "</post>");
                JSONObject json = JSONObject.Parse(request.downloadHandler.text);

                foreach (var childJson in json)
                {
                    if (childJson.Key != "error" && childJson.Key != "result")
                    {
                        JSONObject row = JSONObject.Parse(childJson.Value.ToString());
                        float position_x = (float)row.GetNumber("position_x");
                        float position_y = (float)row.GetNumber("position_y");
                        float position_z = (float)row.GetNumber("position_z");
                        float rotation_x = (float)row.GetNumber("rotation_x");
                        float rotation_y = (float)row.GetNumber("rotation_y");
                        float rotation_z = (float)row.GetNumber("rotation_z");
                        float rotation_w = (float)row.GetNumber("rotation_w");
                        float scale_x = (float)row.GetNumber("scale_x");
                        float scale_y = (float)row.GetNumber("scale_y");
                        float scale_z = (float)row.GetNumber("scale_z");

                        cube.position = new Vector3(position_x, position_y, position_z);
                        cube.rotation = new Quaternion(rotation_x, rotation_y,
                                                        rotation_z, rotation_w);
                        cube.localScale = new Vector3(scale_x, scale_y, scale_z);

                        yield return new WaitForSeconds(delayTime);
                    }
                }
            }
        }
    }
    public void StopState()
    {
        objState = OBJ_STATE.NOSTATE;
    }
}
