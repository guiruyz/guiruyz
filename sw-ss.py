from serial import Serial

class ssctc:
    def __init__(self, port, spd = 9600):
        self.connection = Serial(port, sdp, write_timeout=0.2, timeout=0.2)
