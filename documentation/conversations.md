#### Adding Conversations
In this section, I'll describe how to add conversations to the creatures you create. 

In order to add conversation support to your creature, you will need to inherit the appropriate realization (/lib/realizations, either: companion.c, 
henchman.c, or npc.c). For example:
```
inherit "/lib/realizations/npc.c";
```
Then, you need to make use of the `addConversation` method in your setup function.
```
public void Setup()
{
    // Various creature creation method calls as described in
    // the monsters documentation.

    addConversation("/some/path/to/your/conversation/file.c");
    addConversation("/another/conversation.c");
}
```
##### What's a conversation file?
There are several methods of interest when creating conversation trees. Each of 
these method calls are placed in the `Setup()` method as is typical of many things
created in this lib.
 
```
inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    
}
```
###### The methods:
`void addTopic(string id, string template)`

This method is used to add points of conversation that the NPC will speak about. 
Let's dissect an example:
```
    addTopic("I'm a farmer", "@D@The figure sighs in a faux, wounded tone, "
        "@S@`Very well, I shall humor you, ##ActorName##. We are simple mushroom "
        "farmers. The corpses we collect because they suit our needs... My garb "
        "and trinkets, I wear because they are comfortable and will become "
        "increasingly so as the autumn gives way to winter. This building is here "
        "both for storage and for the harvesting of... our crop. As for the "
        "'thunderclap' as you quaintly put it, well... that's just a fun little "
        "trick that a dear old friend taught me. As for the question about me "
        "forcing you to kill your comrades, well, I'm not the one who caused you "
        "to shoot or swing a sword at them, now am I? For that, at least, you "
        "should consider me blameless.'");
```
The first argument is simply the identifier for a topic and is used by other methods to 
tie them to this topic. The second argument is the template used by the parser for display
of the topic when the NPC is spoken to.

The ID can be any text string, but there are two special topic IDs that are handled differently
than others:

- `"first conversation"` is the conversation topic that is displayed the first time a player talks to the character.
- `"default"` is the default conversation that is displayed on all subsequent 'talk' attempts unless a special state is initiated.In other words, the default conversation is always repeatable.

Using `addTopic`, all topics other than default can only be spoken once.

The template is simply free-form text. However, there are several special tags that the parser
interprets during parsing:

- `@D@`: The text following this will be changed into the color that signifies it as descriptive text.
- `@S@`: The text following this will be changed into the color that signifies it as spoken text.
- `@A@`: The text following this will be changed into the color that signifies it as a skill used or prerequisite met when seeing this text.
- `@I@`: The text following this will be changed into the color that signifies it as an action taken.
- `@H@`: The text following this will be changed into the color that signifies it as highlighted text.
- `@E@`: The text following this will have all previous formatting removed.
- `@C@`: The character immediately following this will be capitalized. This is particularly useful in concert with several of the following tags.
- `##InitiatorName##`: This is replaced by the name of the conversation's initiator. Depending on whether it's second or third person, it will be "you" or the real name.
- `##ActorName##`: This is replaced by the name of the conversation's initiator and will always be the real name.
- `##TargetName##`: This is replaced by the name of the conversation's target. Depending on whether it's second or third person, it will be "you" or the real name.
- `##InitiatorPossessive##`: This is replaced with the possessive pronoun for the initiator. `##TargetPossessive##` does the same, but for the target of the conversation instead.
- `##InitiatorObjective##`: This is replaced with the objective pronoun for the initiator. `##TargetObjective##` does the same, but for the target of the conversation instead.
- `##InitiatorSubjective##`: This is replaced with the subjective pronoun for the initiator. `##TargetSubjective##` does the same, but for the target of the conversation instead.
- `##InitiatorPossessive::Name##`: This is replaced with the possessive noun for the initiator. `##TargetPossessive::Name##` does the same, but for the target of the conversation instead.
- `##SimileDictionary##`: This is replaced by an entry from a supplied similie dictionary. See /lib/core/messageParser.c for details.
- `##Infinitive::<some verb>##`: This is replaced by the supplied verb in the proper form (second person, third person, etc).

 
`void addConditionalTopicAddendum(string id, string addendumID,
    mapping prerequisite, string template)`

This method attaches additional content to a topic when the prerequisite is met. The first argument is simply the identifier 
for a topic and is used by other methods to tie them to this topic and the second is an 
identifier for this topic addendum. The third argument is a prerequisite mapping as defined in /lib/core/prerequisites.c and
the fourth argument is the template that is attached to the original topic when the prerequisites are met.

`void addRepeatableTopic(string id, string template)`

This method is identical to `addTopic` with the subtle distinction that the added topics can be repeated during subsequent talk requests.

`void addTopicPrerequisite(string id, mapping prerequisite)`

This method attaches a condition to whether or not a topic is displayed based on whether or not the
passed-in prerequisite is met.

`void addTopicEvent(string id, string event)`

This method adds an event that will be fired when the associated topic is spoken. This event can
be listened-to by any event handler that is listening for the event. See /lib/core/events.c for more details.

`void addTopicTrigger(string id, string event)`

This method adds an event handler that will trigger the display of the topic when the 
passed event is fired. The character must be set up as a listener for this to happen. 
See /lib/core/events.c for more details.

`void addTopicInterjection(string id, string actor, string actorTopic)`

This method allows for a different character to interject their input on a topic when
they are present during the time it is spoken. For example:
```
    addTopicInterjection("I'm a farmer",
        "/a/different/npc.c",
        "shut up");
```
This would have the /a/different/npc.c character speak their "shut up" topic when the
previously-added "I'm a farmer" topic is spoken.

`void addResponse(string id, string selection, string template)`

This method adds potential responses for a topic to the response menu. The second parameter doubles
as the ID for the response as well as the text displayed in the menu. The third parameter is
the template for the message that is spoken if this response is selected.

`void addResponsePrerequisite(string id, string selection, 
    mapping prerequisite, int alwaysShow)`

This method attaches a condition to whether or not a response is displayed based on whether or not the
passed-in prerequisite is met. If the prerequisite is not met, the response option will not be shown.
The alwaysShow parameter will override this behavior when set - IE: a disabled response will be displayed.

`void addResponseEvent(string id, string selection, string event)`

This method adds an event that will be fired when the associated response is spoken. This event can
be listened-to by any event handler that is listening for the event. See /lib/core/events.c for more details.

`void addResponseEffect(string id, string selection, mapping effect)`

This method ties an effect to the speaking of a given response. These effects can be:

- `([ "vanish": 1 ])` The actor speaking will be silently removed from the area.
- `([ "move": "/path/to/new/location.c" ])` The actor speaking will be moved to a new location
- `([ "attack": 1 ])` The actor speaking will attack the respondent.
- `([ "opinion": -5 ])` The actor speaking will have their opinion of the respondent altered by the supplied value.
- `([ "give": "/path/to/item.c" ])` The actor speaking will give the respondent an item.

`void addResponseTopic(string id, string selection, string topic)`

This method ties a response (the ID and selection pair) to a different topic whose ID is passed
in as the third parameter.

###### Additional information

There are many concrete examples of conversations in the /lib/tutorial/characters directory.
