/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

/*
 copied UDT 1:
 */

#include <iostream>
#include <cmath>


struct Facility
{
    Facility ( int c = 1 ) : hoursBooked(c) { std::cout << "Facility ctor" << std::endl; }
    int hoursBooked = 8;
    ~Facility () { std::cout << "Facility dtor" << std::endl; }

    int chargeCleaningFee( int start, int laborFee );
};

int Facility::chargeCleaningFee( int start, int laborFee )
{
    Facility c(start);
    while( c.hoursBooked <= 10 )
    {
        ++c.hoursBooked;
        return c.hoursBooked + laborFee;      
    }
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

void RecordingStudio::sendInvoice(){}
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
        void useSaturation(); //NTS: new member function added for S&L task
    };

    void increaseWetness( MixKnob increase);
    void decreaseWetness( MixKnob decrease);
    void engageSmartMute( int audioInput = 1, float audioOutput = 1.1f);

    void captureAudio();
    char addTextInfo();
    float widenSignal();
    void showPluginWindow( float mem); //NTS: new member function added for S&L task
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
}
char StereoWidenerAudioPlugin::addTextInfo() { return 't'; }
float StereoWidenerAudioPlugin::widenSignal() { return 100.0f; }
void StereoWidenerAudioPlugin::MixKnob::calculateTickMarks()
{
    std::cout << "calcTicksNum func: Ticks number: " << ticksOnSlider << std::endl;
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
    std::string handlebar = "Flat"; //a member variable that IS initialized in-class
    int bottleHolders = 2;
    int rides = { 5 }; //a member variable that IS initialized in-class

    struct Spokes
    {
        Spokes() { std::cout << "Spokes ctor" << std::endl; }
        ~Spokes() { std::cout << "Spokes dtor" << std::endl; }
        int maxNumSpokes = 8;
        int minNumSpokes = 0;

        void repairSpokes( int spokeNumber );
    };

    void transportPerson();
    void rollDownhill();
    void makeRepairs();
};

void Bicycle::makeRepairs()
{
    std::cout << "Make repairs after this many rides: " << rides << std::endl;
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


    Bicycle::Spokes wheel;
    wheel.repairSpokes ( 0 );

    std::cout << "Is purple's member variable 'rides' equal to 5? " << (purple.rides == 5 ? " Yes" : " No") << "\n" << std::endl;

    Facility allStudios;
    allStudios.chargeCleaningFee( 1, 10);

    RecordingStudio soundbylaura;//NTS: Creates an instance of the RecordingStudio struct named soundbylaura.
    RecordingStudio::ControlRoom  controlRoomB;//NTS: Creates an instance of the nested RecordingStudio::ControlRoom struct named controlRoomB.

    // controlRoomB.bookRoom( true, 5);
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

    FancEQ instance;
    instance.useDefaultKnob( false, true);
    instance.addNewCustomer();

    std::cout << "good to go!" << std::endl;
}
