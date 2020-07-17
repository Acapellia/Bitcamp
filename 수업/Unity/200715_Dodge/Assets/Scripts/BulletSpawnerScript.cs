using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletSpawnerScript : MonoBehaviour
{
    public GameObject bulletPrefab;
    public float spawnRateMin;
    public float spawnRateMax;

    private Transform target;
    private float spawnRate;
    private float timeAfterSpawn;

    // Start is called before the first frame update
    void Start()
    {
        timeAfterSpawn = 0f;
        spawnRate = Random.Range(spawnRateMin, spawnRateMax);
        target = FindObjectOfType<_02_PlayerScript>().transform; // 처리 비용이 큼, update에서 사용하면 많이 느려짐
    }

    // Update is called once per frame
    void Update()
    {
        timeAfterSpawn += Time.deltaTime;

        if(timeAfterSpawn >= spawnRate)
        {
            timeAfterSpawn = 0f;

            GameObject bullet = Instantiate(bulletPrefab, transform.position, transform.rotation);
            bullet.transform.LookAt(target);

            spawnRate = Random.Range(spawnRateMin, spawnRateMax);
        }
    }
}
