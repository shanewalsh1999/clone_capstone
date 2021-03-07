function serial_monitor
    % Uno tag was serial('/dev/cu.usbserial-DN03FOK0');

    %% Initialization
    % Clear any preexisting serial monitor objects
    instrreset;
    
    % s: serial monitor object of arduino
    s = serial('/dev/cu.usbserial-1420');
    fopen(s);
    
    
    %% Loop
    while 1
        monitor = fscanf(s, '%i');
        fprintf('%i\n', monitor);
    end
end