#include <math_tools/bspine.h>


tybspline::tybspline(){}
tybspline::~tybspline(){}

bool tybspline::init(const Eigen::MatrixXd &points, const int &degree){
    mcontrol_points = points;
    p_ = degree;

    n_ = mcontrol_points.cols() - 1;
    m_ = p_ + n_ + 1;

    interval_ = 1.0 / (m_ + 1);

    mknot = Eigen::VectorXd::Zero(m_ + 1);

    for (int i = 0; i <= m_; ++i)
    {

      if (i <= p_)
      {
        mknot(i) = double(-p_ + i) * interval_;
        // mknot(i) = 0;
      }
      else if (i > p_ && i <= m_ - p_)
      {
        mknot(i) = mknot(i - 1) + interval_;
      }
      else if (i > m_ - p_)
      {
        mknot(i) = mknot(i - 1) + interval_;
      }
    }
    
    return true;
}

void tybspline::setKnot(const Eigen::VectorXd &knot) { mknot = knot; }

Eigen::VectorXd tybspline::getKnot(){return mknot;};

Eigen::MatrixXd tybspline::getControlPoints(){ return mcontrol_points;};

void tybspline::setUniformKnot(){
    mknot = Eigen::VectorXd::Zero(m_ + 1);
    for (int i = 0; i <= m_; ++i)
    {

      if (i <= p_)
      {
        mknot(i) = 0;
      }
      else if (i > p_ && i <= m_ - p_)
      {
        mknot(i) = mknot(i - 1) + interval_;
      }
      else if (i > m_ - p_)
      {
        mknot(i) = 1;
      }
    }
};

Eigen::VectorXd tybspline::evaluateDeBoor(const double &u)
{
    double ub = std::min(std::max(mknot(p_), u),mknot(m_ - p_));
    // double ub = u;
    // determine which [ui,ui+1] lay in
    int k = p_;
    while (true)
    {
        if (mknot(k + 1) >= ub)
        break;
        ++k;
    }

    /* deBoor's alg */
    std::vector<Eigen::VectorXd> d;
    for (int i = 0; i <= p_; ++i)
    {
        d.push_back(mcontrol_points.col(k - p_ + i));
        // cout << d[i].transpose() << endl;
    }

    for (int r = 1; r <= p_; ++r)
    {
        for (int i = p_; i >= r; --i)
        {
        double alpha = (ub - mknot[i + k - p_]) / (mknot[i + 1 + k - r] - mknot[i + k - p_]);
        // std::cout << "alpha: " << alpha << std::endl;

        d[i] = (1 - alpha) * d[i - 1] + alpha * d[i];
        }
    }
    // std::cout << "d[p_] =  " << d[p_] << std::endl;
    return d[p_];
} 

