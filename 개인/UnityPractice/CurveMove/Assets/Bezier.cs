using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bezier : MonoBehaviour
{
    public LineRenderer lineRenderer;
    public Transform point0, point1, point2, point3;
    public Transform subway;
    private int numPoints = 50, idx=0;
    private Vector3[] positions = new Vector3[50];

    // Start is called before the first frame update
    void Start()
    {
        //lineRenderer.SetVertexCount(numPoints);
        lineRenderer.positionCount = numPoints;
        //DrawLinearCurve();
        //DrawQuadraticCurve();
        DrawCubicCurve();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void DrawLinearCurve() {
        for(int i = 1; i < numPoints+1; i++) {
            float t = i / (float)numPoints;
            positions[i - 1] = CalculateLinearBezierPoint(t, point0.position, point1.position);
        }
        lineRenderer.SetPositions(positions);
    }
    private void DrawQuadraticCurve() {
        for(int i = 1; i < numPoints+1; i++) {
            float t = i / (float)numPoints;
            positions[i - 1] = CalculateQuadraticBezierPoint(t, point0.position, point1.position, point2.position);
        }
        lineRenderer.SetPositions(positions);
    }
    private void DrawCubicCurve() {
        for(int i = 1; i < numPoints+1; i++) {
            float t = i / (float)numPoints;
            positions[i - 1] = CalculateCubicBezierPoint(t, point0.position, point1.position, point2.position, point3.position);
        }
        lineRenderer.SetPositions(positions);
    }
    private Vector3 CalculateLinearBezierPoint(float t, Vector3 p0, Vector3 p1) {
        return p0 + t * (p1 - p0);
    }
    private Vector3 CalculateQuadraticBezierPoint(float t, Vector3 p0, Vector3 p1, Vector3 p2) {
        // B(t) = (1-t)^2*p0 + 2(1-t)*p1 + t^2*p2
        float u = 1 - t;
        float uu = u * u;
        float tt = t * t;
        Vector3 p = uu * p0;
        p += 2 * u * t * p1;
        p += tt * p2;
        return p;
    }
    private Vector3 CalculateCubicBezierPoint(float t, Vector3 p0, Vector3 p1, Vector3 p2, Vector3 p3) {
        // B(t) = (1-t)^3*p0 + 3(1-t)^2*t*p2 + 3(1-t)*t^2*p2 + t^3*p3 
        float u = 1 - t;
        float uu = u * u;
        float uuu = u * u * u;
        float tt = t * t;
        float ttt = t * t * t;
        Vector3 p = uuu * p0;
        p += 3 * uu * t * p1;
        p += 3 * u * tt * p2;
        p += ttt * p3;
        return p;
    }
}
