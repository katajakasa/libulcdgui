libulcdgui
==========

About
-----
A simple library for drawing a simple GUI on uLCD-32pt serial touch screen.
Requires the libulcd32pt library.

License
-------
MIT. Read LICENSE for more detailed information.

Todo
----
* Documentation :)
* Decorators. Eg. Button could ask ButtonDecorator how it should draw itself. 
  The decorator could either draw primitives or eg. load SVG and draw that.
* Cache. The device can save areas of screen as files and load them. 
  Would be nice to cache the complex stuff and then quickly load if from SD.
* Some sort of draw buffer. Since the device has some sort of receive buffer, 
  we could try to keep that filled with stuff to do. ATM the library just 
  performs an operation and then waits for an ACK.
* Component: Progressbar
* Component: IconButton
* Component: TextArea
* Component: Textfield
* Component: Passwordfield
* Component: IPAddressField
* Component: Panel
* Component: TextLabel
* Sizer: GridSizer (size (n,n) )
* Sizer: FormSizer (size (2,n), label on top, borders)
* Object: Timer
* Dialog frame
* Virtual keyboard dialog (like in cellphones)
* Some sort of notification/confirmation/error dialog

Example
-------
    #include <string>
    #include <iostream>

    #include <ulcdgui/frame.h>
    #include <ulcdgui/lcddevice.h>
    #include <ulcdgui/guiexception.h>
    #include <ulcdgui/components/button.h>
    #include <ulcdgui/sizers/hsizer.h>
    #include <ulcdgui/sizers/vsizer.h>

    bool run = true;

    // This is a callback function for quit button.
    void quit(GuiEvent *ev, void *userdata) {
        run = false;
    }

    int main() {
        // Initialize device
        LCDDevice *dev;
        try {
            dev = new LCDDevice("COM3"); // On linux eg. "/dev/ttyUSB0" etc.
        } catch(GuiException &ex) {
            std::cout << ex.getText() << std::endl;
            return 0;
        }

        // Create a frame. Fills the whole screen.
        Frame *frame = new Frame(dev);

        // Now create some components (buttons, yay!)
        Button *b1 = new Button("Button 1");
        Button *b2 = new Button("Button 2");
        Button *b3 = new Button("Button 3");
        Button *b4 = new Button("Quit");

        // Connect a quit function to button b4
        b4->clicked.connect(sigc::ptr_fun(quit));

        // Create a vertical sizer, and add 3 buttons in it
        VSizer *vs = new VSizer;
        vs->add(b2);
        vs->add(b3);
        vs->add(b4);

        // Create a horizontal sizer, and add button 1 and our vertical sizer in it
        HSizer *hs = new HSizer;
        hs->add(b1);
        hs->add(vs);

        // Set horizontal sizer as root sizer
        frame->setBaseSizer(hs);

        // Run the gui.
        // A single run() call will draw the gui and then check for touch events
        // Run() may throw some surprises :)
        while(run) {
            try {
                frame->run();
            } catch(GuiException &ex) {
                std::cout << "Error while running: " << ex.getText() << std::endl;
                return 0;
            }
        }

        // Delete frame and device objects.
        // Deleting frame will kill all objects that were added to it
        // eh. buttons, sizers, ...
        delete frame;
        delete dev;
        return 0;
    }