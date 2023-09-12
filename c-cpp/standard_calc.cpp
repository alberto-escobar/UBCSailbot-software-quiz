#include "stdbool.h"
#include "standard_calc.h"
#include <math.h>
/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
    //Convert angle it is in range of (-360,360)
    angle = angle - (int)(angle/360)*360.0;

    //Check angle value and bound it to range of [-180,180)
    float boundAngle;
    if (angle >= 180.0) {
        boundAngle = angle - 360.0;
    }
    else if (angle < -180.0) {
        boundAngle = angle + 360.0;
    }
    else {
        boundAngle = angle;
    }
    return boundAngle;
}

/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 * 
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {
    
    //Convert given angles to be in range of [-180,180)
    first_angle = bound_to_180(first_angle);
    middle_angle = bound_to_180(middle_angle);
    second_angle = bound_to_180(second_angle);

    //Normalize first_angle and second_angle with respect to middle_angle
    float normalized_first_angle = bound_to_180(first_angle - middle_angle);
    float normalized_second_angle = bound_to_180(second_angle - middle_angle);

    //Middle_angle is not in reflex region if:
    //normalized_first_angle is in quadrant I and normalized_second_angle is in quadrant IV OR
    //the normalized_first_angle is in quadrant IV and normalized_second_angle is in quadrant I
    if (normalized_first_angle >= 0 
        && normalized_second_angle <= 0
        && normalized_first_angle - normalized_second_angle <= 180){
            return true;
        } 
        
    else if (normalized_first_angle <= 0
          &&  normalized_second_angle >= 0
          && normalized_second_angle - normalized_first_angle <= 180) {
            return true;
        }
        
    else {
        return false;
    }
}