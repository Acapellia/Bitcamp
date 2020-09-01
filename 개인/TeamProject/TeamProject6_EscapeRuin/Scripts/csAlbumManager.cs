using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.UI;

public class csAlbumManager : MonoBehaviour
{
    public GameObject tempAlbumSlot;
    public static Object albumSlot;
    static GameObject albumContents;
    static DirectoryInfo dir;
    static FileInfo[] info;
    static Image[] albumImg;
    // Start is called before the first frame update
    private void Start() {
        albumSlot = tempAlbumSlot;
    }
    public static void initAlbum() {
        //albumContents = GameObject.Find("AlbumContents").gameObject;
        albumContents = csUIManagerControll.albumcontents;
        albumImg = albumContents.gameObject.GetComponentsInChildren<Image>();
        dir = new DirectoryInfo(Application.dataPath);
        info = dir.GetFiles("*.png");
        Debug.Log(info.Length);
        foreach (Image img in albumImg) {
            Debug.Log(img.name);
        }
        for(int i = 0; i < info.Length; i++) {
            byte[] data = File.ReadAllBytes(info[i].ToString());
            Texture2D texture = new Texture2D(2, 2);
            texture.LoadImage(data);
            Sprite sprite = Sprite.Create(texture, new Rect(0, 0, texture.width, texture.height), new Vector2(0.5f, 0.5f), 100.0f);
            if(i >= albumImg.Length) {
                //Debug.Log("size up");
                GameObject albumslot = Instantiate(albumSlot) as GameObject;
                albumslot.transform.parent = albumContents.transform;
                albumImg = albumContents.gameObject.GetComponentsInChildren<Image>();
            }
            albumImg[i].name = "AlbumSlot" + (i + 1);
            albumImg[i].sprite = sprite;
            albumImg[i].transform.localScale = new Vector3(1, 1, 1);
            albumImg[i].color = Color.white;
        }
    }
}
