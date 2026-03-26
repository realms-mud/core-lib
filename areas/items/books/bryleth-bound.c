//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "The Binding of Bryleth");
    set("short", "A book titled 'The Binding of Bryleth'");
    set("title", "The Binding of Bryleth: A Record of Her Fall");
    set("aliases", ({ "bryleth", "binding", "vain queen",
        "kharand histories", "book", "binding of bryleth",
        "the binding of bryleth" }));
    set("long", "This volume records the capture and imprisonment of "
        "Bryleth the Vain, last ruler of Kharand's shadowed age. "
        "Though written in the tone of history, the account bears "
        "uneasy gaps, contradictions, and hints of truths left "
        "unspoken. It is said this record was sealed for good reason.");

    addChapter("Chapter 1: The Queen Unmasked",
        "In the years after Kharand's fall, Bryleth was not found.\n"
        "Many believed she had fled beyond reach, or perished unseen.\n"
        "Yet whispers persisted among the learned and the wary.\n"
        "She had endured where no mortal woman could have endured.\n"
        "Her reign spanned centuries without decay or frailty.\n"
        "Those who served her spoke of beauty untouched by time.\n"
        "Others spoke in quieter tones of something beneath the mask.\n"
        "Records from her court were incomplete, altered, or burned.\n"
        "Servants vanished, and those who remained would not speak.\n"
        "It was said mirrors were covered in her presence.\n"
        "And that she never cast a shadow when candles burned low.\n"
        "The alliance could not allow such a being to remain free.\n"
        "Thus began the quiet hunt for the vanished queen.\n"
        "Not with armies, but with watchers, scholars, and hunters.\n"
        "Years passed before the first true sign was uncovered.\n"
        "A village emptied in a single night without struggle.\n"
        "No blood, no tracks, only silence and cold hearths.\n"
        "The pattern was recognized by those who knew her hand.\n"
        "Bryleth had not fled. She had merely withdrawn.\n"
        "And in that withdrawal, she had begun again.");

    addChapter("Chapter 2: The Hunt in Silence",
        "The pursuit of Bryleth was not proclaimed to the people.\n"
        "Panic would have undone what fragile peace remained.\n"
        "Instead, a small company was assembled in secrecy.\n"
        "Knights, mages, and those who had faced darker things.\n"
        "They followed absence more than presence.\n"
        "Empty roads, abandoned farms, extinguished lives.\n"
        "Wherever she passed, something of the world dimmed.\n"
        "One account speaks of a forest gone gray overnight.\n"
        "Another of a river where no reflection could be seen.\n"
        "The company learned not to speak her name aloud.\n"
        "For twice, doing so was followed by sudden death.\n"
        "They tracked her to the broken lands of old Kharand.\n"
        "There, the air itself seemed unwilling to move.\n"
        "Ruins stood as they had been left, yet altered subtly.\n"
        "Paths twisted. Distances betrayed the eye.\n"
        "At the heart of this stillness, they found her.\n"
        "Not enthroned, nor armored, but waiting.\n"
        "She greeted them as one greets expected guests.\n"
        "And she smiled, as though nothing had been lost.\n"
        "Several accounts end abruptly at this moment.");

    addChapter("Chapter 3: The Price of Victory",
        "What transpired in that meeting is not fully recorded.\n"
        "Surviving accounts disagree, or fail entirely.\n"
        "Some claim she spoke, and men fell to their knees weeping.\n"
        "Others claim she moved, and half the company died at once.\n"
        "One fragment states that she laughed as steel struck her.\n"
        "Yet all agree on one point: she could not be slain.\n"
        "Blades failed. Fire faltered. Even magic recoiled.\n"
        "It was then that binding, not destruction, was chosen.\n"
        "The mages enacted a working prepared in deepest secrecy.\n"
        "A prison not of walls, but of layered reality.\n"
        "A place removed, yet anchored to the world.\n"
        "The cost of this working was not small.\n"
        "Of those present, few survived its completion.\n"
        "The knights held her as long as they were able.\n"
        "Witnesses say the ground itself screamed.\n"
        "Light bent. Sound fractured. Time lost meaning.\n"
        "And when it ended, she was gone.\n"
        "Not destroyed, but contained beyond reach.\n"
        "Those who lived would not speak of what they saw.\n"
        "Only that the victory felt like defeat.");

    addChapter("Chapter 4: The Prison Without Door",
        "The prison of Bryleth was sealed without monument.\n"
        "No tower marks it. No gate reveals its presence.\n"
        "Its location was divided among orders and hidden.\n"
        "Even in record, it is described only in riddles.\n"
        "It is said to exist where space forgets itself.\n"
        "Where steps may lead both forward and away.\n"
        "Where sound arrives before it is made.\n"
        "The binding was designed to endure beyond ages.\n"
        "Yet no work of mortal or immortal craft is perfect.\n"
        "Thus were warnings placed within scattered texts.\n"
        "Not openly, but veiled in story and contradiction.\n"
        "This volume is one such warning, though incomplete.\n"
        "For the full truth is not written here.\n"
        "Perhaps it cannot be written.\n"
        "Or perhaps it must not be.\n"
        "There are those who believe she still speaks.\n"
        "Not with voice, but with influence and dream.\n"
        "If so, the prison is not silent.\n"
        "And silence was its only true safeguard.\n"
        "May it remain unbroken.");
}
