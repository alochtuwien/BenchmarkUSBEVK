#include <metavision/sdk/driver/camera.h>
#include <metavision/sdk/base/events/event2d.h>
#include <chrono>
#include <thread>
class EventBufferReader {
public:
    EventBufferReader() {

    }

    void readEvents(const Metavision::Event2d *ev_begin, const Metavision::Event2d *ev_end) {
        auto now_ms = std::chrono::system_clock::now();
        auto epoch = now_ms.time_since_epoch();
        auto value = std::chrono::duration_cast<std::chrono::microseconds>(epoch);
        std::cout << "" << ev_begin->t << " " << (ev_end - 1)->t << " " << value.count() << std::endl;
    }

};


// main loop
int main(int argc, char *argv[]) {
    Metavision::Camera cam; // create the camera

    if (argc >= 2) {
        // if we passed a file path, open it
        cam = Metavision::Camera::from_file(argv[1]);
    } else {
        // open the first available camera
        cam = Metavision::Camera::from_first_available();
    }
    EventBufferReader reader;
    cam.cd().add_callback([&reader](const Metavision::EventCD *ev_begin, const Metavision::EventCD *ev_end)
                                    { reader.readEvents(ev_begin, ev_end); });

    // start the camera
    cam.start();



    // keep running while the camera is on or the recording is not finished
    while (cam.is_running()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//        std::cout << "Camera is running!" << std::endl;
    }

    // the recording is finished, stop the camera.
    // Note: we will never get here with a live camera
    cam.stop();
}
