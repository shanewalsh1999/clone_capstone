for cycle = 1:5
    for val = 70:128
        write(muscleOneVoltage, val);
        java.lang.Thread.sleep(0.02*1000); 
    end
    
    for val = 128:-1:70
        write(muscleOneVoltage, val);
        java.lang.Thread.sleep(0.02*1000);
    end
end