/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




/*
 copied UDT 1:
 */

#include <iostream>
#include <cmath>


struct Facility
{
    Facility ( int c = 20 ) : hoursBooked(c) { std::cout << "Facility ctor" << std::endl; }
    int hoursBooked;
    int threshold = 8;
    int laborFee = 100;
    int facilityFee = 110;
    ~Facility () { std::cout << "Facility dtor" << std::endl; }

    int chargeCleaningFee( int start, int cleaningFee );
};

int Facility::chargeCleaningFee( int start, int cleaningFee )
{
    Facility c(start);
    while( c.hoursBooked <= 10 )
    {
        ++c.hoursBooked;
        if ( c.hoursBooked >= threshold )
            std::cout << "Add cleaning fees after " << this->hoursBooked << " hours." << std::endl;
    }
    std::cout << "Total fees: $" << hoursBooked * (facilityFee + cleaningFee) << std::endl;
    return 0;
}

struct RecordingStudio
{
    RecordingStudio() { std::cout << "RecordingStudio ctor" << std::endl; }
    ~RecordingStudio() { std::cout << "RecordingStudio dtor" << std::endl; }
    int microphones = 28;
    int numOfClients = 33;
    float expenseCatering { 300.0f };
    float expenseInsurance = 1100.0f;
    int employees {8};
    int discount = 10;

    struct ControlRoom
    {
        ControlRoom() { std::cout << "ControlRoom ctor" << std::endl; }
        ~ControlRoom() { std::cout << "ControlRoom dtor" << std::endl; }
        bool isBooked = false;
        float ratePerHour = 500.0f;
        std::string consoleType = "Analog";
        bool clientHasEngineer = false;
        int hoursOn;

        void bookRoom( bool isBooked = true, int numberOfClients = 5);
        void prepareRoom( bool powerOn = true, bool roomCleaned = true, int numberOfAssistants = 1, float rateForAssistant = 5.0f);
        float caclulateTotalFee( float numberOfActualHours = 12.0f, float overtimeRate = 650.50f, float reelsUsed = 4.0f);
        void resetLights ( int hoursOn);
    };

    void beginRecordingSession( ControlRoom controlRoomA);
    void startRateClock( bool hasGroupon);
    void closeRoom( ControlRoom controlRoomA, bool equipmentOff = true);
    int billClient( ControlRoom controlRoomA, int hoursUsed = 12, int tapesUsed = 3, int woofersBlown = 3);

    void sendInvoice();
    void hostEvent();
    void recordAudio();
};

void RecordingStudio::recordAudio()
{
     std::cout << "Max number of mics allowed: " << microphones << std::endl;   
}

void RecordingStudio::beginRecordingSession( ControlRoom controlRoomA)
{
    controlRoomA.isBooked = false;
}

void RecordingStudio::startRateClock( bool hasGroupon)
{
    if( hasGroupon == false )
        discount = 0;  
}

void RecordingStudio::closeRoom( ControlRoom controlRoomA, bool equipmentOff)
{
    if( equipmentOff == true )
        controlRoomA.isBooked = false;
}

int RecordingStudio::billClient(ControlRoom controlRoomA, int hoursUsed, int tapesUsed, int woofersBlown)
{
    hoursUsed = 4;
    tapesUsed = 4;
    woofersBlown = 4;
    controlRoomA.isBooked = false;

    return hoursUsed + tapesUsed + woofersBlown;
}

void RecordingStudio::ControlRoom::bookRoom( bool isRoomBooked, int numberOfTotalClients)
{
    if( isRoomBooked == true )
    {
        numberOfTotalClients = 2;
        std::cout << "Room booked " << this->isBooked << "at $" << this->ratePerHour << " dollars/min." << std::endl;
    }
    else
    {
        numberOfTotalClients = 0;
    }
}

void RecordingStudio::ControlRoom::prepareRoom( bool powerOn, bool roomCleaned, int numberOfAssistants, float rateForAssistant)
{
    if( roomCleaned == true )
    {
        powerOn = true;
        rateForAssistant = 1.1f;
    }
    else
    {
        numberOfAssistants = 1;
    }
    std::cout << "prepRoom func: Constructors give us a way to set up the values of member variables with valid values." << std::endl;
}

float RecordingStudio::ControlRoom::caclulateTotalFee( float numberOfActualHours, float overtimeRate, float reelsUsed)
{
    if( numberOfActualHours >= 8 )
    {
        overtimeRate = 2.0f;
    }
    else
    {
        reelsUsed = 2;
    }
    return ( overtimeRate * numberOfActualHours) + reelsUsed;  
}

void RecordingStudio::sendInvoice()
{
    std::cout << "Are we hosting an event tomorrow:" << (this->employees == 0 ? " Yes" : " No") << "\n" << std::endl;
}
void RecordingStudio::hostEvent()
{
    std::cout << "After the compiler allocates the space required by the type, it calls a special function called the constructor." << std::endl;
}

void RecordingStudio::ControlRoom::resetLights ( int hoursTotal)
{
    for (int on = 1; on < 10; on += 1 )
    {
        ControlRoom control;
        control.hoursOn += on;
    }
    std::cout << "Lights reset after " << hoursTotal << " hours." << std::endl;
}
//small change

/*
 copied UDT 2:
 */
struct StereoWidenerAudioPlugin
{
    StereoWidenerAudioPlugin() : fontSizeToolTips(18)
    {
        std::cout << "SWAP ctor" << std::endl;
    }
    ~StereoWidenerAudioPlugin() { std::cout << "SWAP dtor" << std::endl; }
    int interfaceElements;
    std::string knobsColors = "Black";
    float memoryAllocated { 64.0f };
    int fontSizeToolTips;
    float knobsLocation { 0.0f };
    float memInc = 1.0f;

    struct MixKnob
    {
        MixKnob() : ticksOnSlider(80)
        {
            std::cout << "MixKnob ctor" << std::endl;
        }
        ~MixKnob() { std::cout << "MixKnob dtor" << std::endl; }
        std::string label = "Mix";
        int sliderHeight = 10; 
        int sliderWidth = 2;
        int ticksOnSlider;
        std::string sliderColor = "Black";
        int bytesUsed();

        void getStateInformation( int sizeInBytes, float inputLevel);
        void prepareToPlay( double sampleRate, int samplesPerBlock);
        bool getBypassState( bool customBypassButton, bool nativeBypassButton);
        void calculateTickMarks();
        void useSaturation(); 
    };

    void increaseWetness( MixKnob increase);
    void decreaseWetness( MixKnob decrease);
    void engageSmartMute( int audioInput = 1, float audioOutput = 1.1f);

    void captureAudio();
    char addTextInfo();
    float widenSignal();
    void showPluginWindow( float mem);
};

void StereoWidenerAudioPlugin::increaseWetness( MixKnob increase)
{
    increase.ticksOnSlider = 50;
}

void StereoWidenerAudioPlugin::decreaseWetness( MixKnob decrease)
{
    decrease.ticksOnSlider = 10;
}

void StereoWidenerAudioPlugin::engageSmartMute( int audioInput, float audioOutput)
{
    audioInput = 2;
    audioOutput = 5.1f;
}

void StereoWidenerAudioPlugin::MixKnob::getStateInformation( int sizeInBytes, float inputLevel)
{
    if( sizeInBytes == 256 )
    {
        inputLevel = 2.0f;
    }
    else
    {
        inputLevel = 0.0f;
    }
    std::cout << "getState func: Writing the name of the Type with (); creates the constructor." << std::endl;
}
void StereoWidenerAudioPlugin::MixKnob::prepareToPlay( double sampleRate, int samplesPerBlock)
{
    if( samplesPerBlock == 44100 )
    {
        sampleRate = 2;
    }
    else
    {
        sampleRate = 0;
    }
}
bool StereoWidenerAudioPlugin::MixKnob::getBypassState( bool customBypassButton, bool nativeBypassButton)
{
    if( customBypassButton == true )
    {
        nativeBypassButton = false;
    }
    else
    {
        nativeBypassButton = true;
    }
    return true;
}

void StereoWidenerAudioPlugin::captureAudio()
{
    std::cout << "captureAudio func: Constructors don't have a return type, not even VOID." << std::endl;
    std::cout << "That knob color should be: " << this->knobsColors << "\n" << std::endl;
}
char StereoWidenerAudioPlugin::addTextInfo() { return 't'; }
float StereoWidenerAudioPlugin::widenSignal() { return 100.0f; }
void StereoWidenerAudioPlugin::MixKnob::calculateTickMarks()
{
    std::cout << "calcTicksNum func: Ticks number: " << ticksOnSlider << std::endl;
    std::cout << "The name of that knob should be: " << this->label << "\n" << std::endl;
}

void StereoWidenerAudioPlugin::MixKnob::useSaturation()
{
    bool ready = true;
    while ( ready )
    {
        ready = false;
        std::cout << ("Plugin is ready: ") << (ready ? "true." : "false.") << std::endl;
    }  
}

void StereoWidenerAudioPlugin::showPluginWindow( float mem)
{
    while ( mem <= 64.0f)
    {
        ++mem;
        if( mem >= memoryAllocated )
            std::cout << "showPlugWin func: Welcome to SWAP" << std::endl;
    }
}
/*
 copied UDT 3:
 */
struct Bicycle
{
    Bicycle() { std::cout << "Bicycle ctor" << std::endl; }
    ~Bicycle() { std::cout << "Bicycle dtor" << std::endl; }
    int numGears = 21;
    float tireAirPressure { 70.0f }; //a member variable that IS initialized in-class
    std::string handlebar = "Flat";
    int bottleHolders = 2;
    int rides = { 5 }; 

    struct Spokes
    {
        Spokes() { std::cout << "Spokes ctor" << std::endl; }
        ~Spokes() { std::cout << "Spokes dtor" << std::endl; }
        int maxNumSpokes = 8;
        int minNumSpokes = 0;

        void repairSpokes( int spokeNumber );
        void replaceSpokes();
    };

    void transportPerson();
    void rollDownhill();
    void makeRepairs();
};

void Bicycle::makeRepairs()
{
    std::cout << "Waterbottle holders installed: " << this->bottleHolders << std::endl;
}

void Bicycle::transportPerson()
{
    std::cout << "A constructor's job is to set up the initial values of the member variables. " <<std::endl; 
}

void Bicycle::rollDownhill()
{
    std::cout << "Roll downhill initial ppi: " << tireAirPressure << ". Required bottle holders: " << bottleHolders << std::endl; //making a member function use initialized member variables via std::cout
}


void Bicycle::Spokes::repairSpokes( int spokeNumber )
{
    while( spokeNumber < 8)
    { 
        ++spokeNumber;
        std::cout << "You are on spoke number: " << spokeNumber << std::endl;
        if( spokeNumber >= maxNumSpokes )
            std::cout << "All spokes fixed." << std::endl;
    } 
}

void Bicycle::Spokes::replaceSpokes()
{
    std::cout << "# of spokes replaced: " << this->maxNumSpokes << std::endl;
}

/*
 new UDT 4:
 with 2 member functions
 */
struct BigBoxStore
{
    BigBoxStore() { std::cout << "BigBoxStore ctor" << std::endl; }
    ~BigBoxStore()
    {
        sparklySpokes.repairSpokes(12);
        std::cout << "Sparkly spokes added via the BBS dtor" << std::endl;
    }

    Bicycle newBikes;
    Bicycle::Spokes sparklySpokes;

    void sellNewBikes();
    bool installSparklySpokes( bool newCustomer, bool newSpokes);
};

void BigBoxStore::sellNewBikes()
{
    std::cout << "Selling new bikes: " << newBikes.bottleHolders << std::endl;
}

bool BigBoxStore::installSparklySpokes( bool newCustomer,  bool newSpokes)
{
    if( newCustomer == true )
    { 
        newSpokes = true;
        std::cout << "How many gears do the old bikes have? " << this->newBikes.numGears << "\n" << std::endl;
    }
    return true;
}



/*
 new UDT 5:
 with 2 member functions
 */
struct FancEQ
{
    FancEQ() { std::cout << "FancEQ ctor" << std::endl; }
    ~FancEQ()
    {
        defaultKnob.useSaturation();
        std::cout << "Purple knob adds saturation via the FancEQ dtor" << std::endl;
    }

    RecordingStudio newCustomer;
    RecordingStudio::ControlRoom controlRoomD;
    StereoWidenerAudioPlugin plugin;
    StereoWidenerAudioPlugin::MixKnob defaultKnob;

    bool useDefaultKnob( bool grayKnob, bool purpleKnob);
    void addNewCustomer();
};


bool FancEQ::useDefaultKnob( bool newKnob, bool purpleKnob)
{
    if( newKnob == false )
    {
        purpleKnob = true;
        std::cout << "The # of new customers is: " << this->newCustomer.numOfClients + 1 << "\n" << std::endl;
    }
    return false;
}

void FancEQ::addNewCustomer()
{
    std::cout << "Adding new customer: " << newCustomer.numOfClients << std::endl;
}



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>

int main()
{
    Bicycle purple; //NTS: I am instantiating a UDT named 'purple' in the main()
    purple.transportPerson(); //NTS: I am calling the member functions of the UDT instance
    purple.rollDownhill();
    purple.makeRepairs();

    std::cout << "Water bottle holders installed: " << purple.bottleHolders << std::endl;


    Bicycle::Spokes wheel;
    wheel.repairSpokes ( 0 );
    wheel.replaceSpokes();
    std::cout << "Spokes replaced: " << wheel.maxNumSpokes << std::endl;

    std::cout << "Is purple's member variable 'rides' equal to 5? " << (purple.rides == 5 ? " Yes" : " No") << "\n" << std::endl;

    Facility allStudios;
    allStudios.chargeCleaningFee( 0, 100);

    std::cout << "Add cleaning fee after " << allStudios.hoursBooked << " hours." << std::endl;

    RecordingStudio soundbylaura;//NTS: Creates an instance of the RecordingStudio struct named soundbylaura.
    RecordingStudio::ControlRoom  controlRoomB;//NTS: Creates an instance of the nested RecordingStudio::ControlRoom struct named controlRoomB.

    controlRoomB.bookRoom( true, 5);
    std::cout << "Room booked " << controlRoomB.isBooked << "at $" << controlRoomB.ratePerHour << " dollars/hr." << std::endl;
    
    controlRoomB.prepareRoom( true, true, 1, 5.0f); 
    // controlRoomB.caclulateTotalFee( 12.0f, 650.50f, 4.0f);
    controlRoomB.resetLights ( 10); //NTS: this is the function that is calling the ctor&dtor 10 times
    //NTS: Don't forget, calling functions that have arguments here expect direct values, not type declarations.


    std::cout << "Is the room being prepped?" << (controlRoomB.isBooked == true ? " Yes" : " No") << "\n" << std::endl;   

    // soundbylaura.beginRecordingSession( controlRoomB);
    // soundbylaura.startRateClock( true);
    // soundbylaura.closeRoom( controlRoomB, true);
    // soundbylaura.billClient( controlRoomB, 12, 3, 3);

    soundbylaura.hostEvent();
    soundbylaura.recordAudio();
    soundbylaura.sendInvoice();

    std::cout << "Are we hosting an event today:" << (soundbylaura.employees == 0 ? " Yes" : " No") << "\n" << std::endl;


    StereoWidenerAudioPlugin SBLWide;
    StereoWidenerAudioPlugin::MixKnob mix;

    SBLWide.captureAudio();
    // SBLWide.addTextInfo();
    // SBLWide.widenSignal();
    SBLWide.showPluginWindow( 64.0f);

    // SBLWide.increaseWetness( mix);
    // SBLWide.decreaseWetness( mix);
    // SBLWide.engageSmartMute( 1, 1.1f);

    std::cout << "This knob color should be: " << (SBLWide.knobsColors) << "\n" << std::endl;

    mix.getStateInformation(int (256), float (0.0f));
    mix.prepareToPlay( 44100.0, 256.0f);
    mix.getBypassState( false, false);
    mix.calculateTickMarks();
    mix.useSaturation();

    std::cout << "The name of this knob should be: " << (mix.label) << "\n" << std::endl;

    BigBoxStore walmazon;
    walmazon.sellNewBikes();
    walmazon.installSparklySpokes( true,  true);

    std::cout << "How many gears do the new bikes have? " << (walmazon.newBikes.numGears) << "\n" << std::endl;

    
    // std::cout << "Is the store selling new bikes?" << (walmazon.newBikes) << "\n" << std::endl;

    FancEQ instance;
    instance.useDefaultKnob( false, true);
    instance.addNewCustomer();

    std::cout << "The number of new customers is: " << (instance.newCustomer.numOfClients) + 1 << "\n" << std::endl;

    std::cout << "good to go!" << std::endl;
}
