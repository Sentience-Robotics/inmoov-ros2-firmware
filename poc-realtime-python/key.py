import serial
import threading
import time
from pynput import keyboard

# Replace SERIAL_PORT with the correct port (check PlatformIO Serial Monitor)
SERIAL_PORT = "/dev/tty.usbmodem101"
BAUD_RATE = 9600
SEND_INTERVAL = 0.002  # In seconds, (0.002 = 2ms between sends)

# Track key states
keys_held = set()
running = True

# Try to open the serial port
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
    print(f"Connected to {SERIAL_PORT} at {BAUD_RATE} baud.")
except Exception as e:
    print(f"Failed to connect: {e}")
    exit()

def send_keys():
    """Continuously send key presses while they are held."""
    while running:
        # Make a copy of keys_held to avoid modifying during iteration (thread safety)
        current_keys = set(keys_held)
        for key in current_keys:
            ser.write(key.encode())  # Send key as bytes
            print(f"Sent: {key}")
        time.sleep(SEND_INTERVAL)

def on_press(key):
    """Detect when a key is pressed and start sending it."""
    try:
        if key.char in ['d', 'g']:  # Detect 'd' and 'g'
            keys_held.add(key.char)  # Add to set (prevents duplicates)
    except AttributeError:
        pass  # Ignore special keys

def on_release(key):
    """Detect when a key is released and stop sending it."""
    try:
        if key.char in ['d', 'g']:  # Detect 'd' and 'g'
            keys_held.discard(key.char)  # Remove from set
    except AttributeError:
        pass

    if key == keyboard.Key.esc:
        print("Exiting...")
        global running
        running = False
        ser.close()
        return False  # Stop listener

# Start the continuous sending thread
threading.Thread(target=send_keys, daemon=True).start()

# Start listening for keyboard events
with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
