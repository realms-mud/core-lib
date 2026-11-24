//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Sairen lays the half-mended "
        "net across her knee and checks your hands for cuts. "
        "@S@'You came down the ridge without falling. That is a "
        "better beginning than most people manage. Do you need "
        "directions, a dry place, or an honest answer?'");
    addTopic("the nets", "@S@'Every net has a different repair. "
        "A tear from rock is straight; a tear from a boat hook "
        "pulls sideways. The red twine is mine. The green is "
        "Ilden's, because he insists it is easier to see at dusk.'");
    addTopic("the tide", "@S@'The cave pool looks calm when the "
        "sea is rising. That is when it is most likely to steal "
        "your footing. The ebb rocks are safe only after the "
        "water has turned.'");
    addTopic("your brother", "@D@She folds the net without "
        "looking away. @S@'Deren left with a crew bound north. "
        "He wrote twice. The second letter said the coast was "
        "beautiful and the food was terrible. I have kept his "
        "name on the board because someone should expect him.'");
    addTopic("the wreck", "@S@'The coach was not lost to the "
        "weather. The harness was unbuckled and the prints left "
        "the track on foot. I heard one passenger reached the "
        "mill, but I have not seen her.'");
    addTopic("the hamlet", "@S@'Six households, if you count the "
        "two who only stay through the fishing season. We share "
        "the smokehouse and argue about whose turn it is to "
        "clean it. No one wins that argument.'");
    addTopic("the smokehouse", "@S@'I keep the racks at the "
        "upper end so the children cannot reach them. The smoke "
        "has to stay low and steady. A high fire ruins a week's "
        "catch and makes the whole cove taste of soot.'");

    addResponse("first conversation", "Can you repair my clothing?",
        "@D@Sairen pats the clear patch of landing beside her. "
        "@S@'A torn sleeve, yes. Armor, no. Sit on the dry side "
        "of the landing and keep your boots off my net.'");
    addResponseTopic("first conversation",
        "Can you repair my clothing?", "the nets");
    addResponse("the nets", "Why are the twines different colors?",
        "@D@She lifts the green twine for comparison. "
        "@S@'So I know who owns the net when three of us are "
        "working at once. Ilden thinks it is for show. He is "
        "wrong, but he likes being wrong about small things.'");
    addResponse("first conversation", "Is the tide cave safe?",
        "@D@Sairen points to the dark weed line on the rock. "
        "@S@'Not while the water is rising. Wait for the ebb "
        "and look at the weed line on the rock.'");
    addResponseTopic("first conversation", "Is the tide cave safe?",
        "the tide");
    addResponse("the tide", "How can I tell when the water turns?",
        "@D@She watches the foam recede from the shore. "
        "@S@'The foam stops climbing the black rock and begins "
        "to peel away. If you have to guess, wait another "
        "quarter hour.'");
    addResponse("first conversation", "Who was Deren?",
        "@D@Sairen folds the net across her knee. "
        "@S@'My older brother. He could mend a sail faster than "
        "I can mend a net, which is why I did not believe him "
        "when he said he wanted to travel.'");
    addResponseTopic("first conversation", "Who was Deren?",
        "your brother");
    addResponse("first conversation", "What happened to the coach?",
        "@D@She glances up the track toward the inland shelf. "
        "@S@'The axle broke, but that is not the whole story. "
        "Look at the prints and ask the outpost what they know.'");
    addResponseTopic("first conversation", "What happened to the coach?",
        "the wreck");
    addResponse("the hamlet", "Can I buy smoked fish?",
        "@D@Sairen nods toward the smokehouse. "
        "@S@'Ilden will sell a small share when the boats return. "
        "I can trade a repair for a meal if the catch is good.'");
    addResponseTopic("the hamlet", "Can I buy smoked fish?",
        "the smokehouse");
    addResponse("the wreck", "Do you know where the passenger went?",
        "@D@Sairen shakes her head and studies the track. "
        "@S@'No. I know where the prints lead. I am not going "
        "up that track alone.'");
}
