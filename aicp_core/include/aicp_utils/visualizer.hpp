#pragma once

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

#include <octomap/ColorOcTree.h>

#include <Eigen/Dense>

namespace aicp {

class Visualizer
{
public:
    Visualizer(){

    }
//    ~Visualizer();

    virtual void publishCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud,
                              int param,
                              std::string name,
                              int64_t utime = -1) = 0;

    virtual void publishCloud(pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr& cloud,
                              int param,
                              std::string name,
                              int64_t utime = -1) = 0;

    virtual void publishMap(pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud,
                            int64_t utime,
                            int channel) = 0;

    virtual void publishOctree(octomap::ColorOcTree*& octree,
                               std::string channel_name) = 0;

    virtual void publishPose(Eigen::Isometry3d pose_,
                             int param,
                             std::string name,
                             int64_t utime = -1) = 0;

protected:
    // Set global reference frame to zero origin
    Eigen::Isometry3d global_ = Eigen::Isometry3d::Identity();
};
}