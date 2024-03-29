void MazeSolve() {
  while (1) {
    follow_line();

    analogWrite(rightMotorPWM, 0);
    analogWrite(leftMotorPWM, 0);
    delay(10);

    unsigned char found_left = 0;
    unsigned char found_straight = 0;
    unsigned char found_right = 0;

    readLine();
    if (sensor_values[0] > 300 || sensor_values[1] > 300) {
      found_left = 1;
      Serial.println("Found Left <--");
    }


    if (sensor_values[7] > threshold) {

      found_right = 1;
      Serial.println("Found Right -->");
    }
    analogWrite(rightMotorPWM, MaxSpeed);
    analogWrite(leftMotorPWM, MaxSpeed);
    delay(100);
    // bailout:
    readLine();
    if (sensor_values[2] > threshold || sensor_values[3] > threshold || sensor_values[4] > threshold || sensor_values[5] > threshold) {
      found_straight = 1;
      Serial.println("Found Straight --");
    }


    readLine();
    if (sensor_values[0] > threshold && sensor_values[1] > threshold && sensor_values[2] > threshold && sensor_values[3] > threshold && sensor_values[4] > threshold && sensor_values[5] > threshold && sensor_values[6] > threshold)
      break;
    unsigned char dir = select_turn(found_left, found_straight, found_right);


    turn(dir);


    path[path_length] = dir;
    path_length++;


    simplify_path();
  }
}
