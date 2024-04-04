#include "shape.hpp"

float Point2d::distance(Point2d p)
{
    return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}
float Circle::getPerimeter()
{
    return 2 * 3.14 * m_ratio;
}

float Triangle::getPerimeter()
{
    return m_p1.distance(m_p2) + m_p2.distance(m_p3) + m_p3.distance(m_p1);
}

float Square::getPerimeter()
{
    return 4 * m_edge;
}

float Polygon::getPerimeter()
{
    float sum = 0;
    for (int i = 0; i < m_vertices.size() ; i++)
    {
        if(i == m_vertices.size() )
            sum += m_vertices[i].distance(m_vertices[0]);
        else
            sum += m_vertices[i].distance(m_vertices[i + 1]);

    }
    return sum;
}

