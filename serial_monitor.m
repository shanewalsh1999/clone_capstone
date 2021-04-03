function serial_monitor
    % Uno tag was serial('/dev/cu.usbserial-DN03FOK0');

    %% Initialization
    % Clear any preexisting serial monitor objects
    instrreset;
    
    % s: serial monitor object of arduino
    s = serial('/dev/tty.usbserial-DN03GO3K');
    fopen(s);
    
    %% Loop
    while 1
        monitor = fscanf(s, '%s');
        fprintf('%s\n', monitor);
    end
end