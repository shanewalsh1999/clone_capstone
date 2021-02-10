%% Notes
% HC-05 must be connected over Bluetooth

% Get channel num
% instrhwinfo('Bluetooth','HC-05')

% There should be a manual override just in case Bluetooth fails. Don't
% want relay pin to get stuck in HIGH state.

%% Bluetooth setup
% Close existing filestream (prevents crashes)
if exist('b','var') == 1
    fclose(b);
    clear b;
end

% Create bluetooth object for HC-05 (Bluetooth module attached to Arduino)
b = Bluetooth('btspp://98D371FDB654', 1);

% Allow MATLAB to send data to HC-05
fopen(b);

%% Toggle LED
while 1 
    x = input('Press ENTER to toggle relay (ctrl+C to exit)');
   
    % Send data to HC-05. This toggles the state of the LED.
    fwrite(b,uint8(1));
end
