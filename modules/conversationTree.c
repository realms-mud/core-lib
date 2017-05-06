//*****************************************************************************
// Class: conversationTree
// File Name: conversationTree.c
//
// Copyright (c) 2011 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
virtual inherit "/lib/core/stateObject.c";
virtual inherit "/lib/core/thing.c";

#define Speech "[0;33m"
#define Desc "[0;36m"
#define End "[0m"
#define Stat(x) sprintf("[0;34m[%s][0m", x)
#define Action(x) sprintf("[0;31m[%s][0m", x)

private nosave string defaultMessage = "default";
private nosave mapping responseMap = ([ ]);
private nosave int ignoreTalk = 0;

private nosave mapping objectList = ([
//    "spatula": clone_object("/players/maeglin/eledhel/questObjects/runewall")
]);

private nosave mapping topics = ([
//    "key": ([
//        "template": "Hi there!",
//        "is repeatable": 1, // if this doesn't exist, it's not repeatable
//        "responses": ([
//            "key": ([
//                "template": "some text",
//                "criteria": ([
//                    "stat": "statName";"GreaterThan|LessThan";"value",
//                    "guild": "is|isNot";"value",
//                    "function": "object";"method",
//                    "state": "a state",
//                    "object present": "object"
//                ]),
//                "npc response": "key",
//                "delegate": "other";"key", //trigger comment from other NPC
//                "trigger": "event" // send 'event' to stateMachine
//            ])
//        ]),
//        "criteria": ([ /* same structure as responses criteria */ ]),
//        "trigger": "event"; "name" // send 'name' event to owning stateMachine
//                          "method"; "name" // execute 'name' method on this NPC object
//    ])
]);

public nomask varargs string DefaultMessage(string key)
{
    if(key && stringp(key) && member(m_indices(topics), key))
    {
        defaultMessage = key;
    }
    return defaultMessage;
}

private nomask int isValidResponse(mapping responses)
{
    // TODO: Finish this
    return 1;
}

private nomask int isValidCriteria(mapping criteria)
{
    // TODO: Finish this
    return 1;
}

private nomask int isValidTrigger(mapping topic)
{
    // TODO: Finish this
    return 1;
}

public nomask int addTopic(string key, mapping topic)
{
    int ret = 0;
    if(key && stringp(key) && !member(topics, key) && topic && mappingp(topic) && 
       member(topic, "template") && stringp(topic["template"]) &&
       (!member(topic, "is repeatable") || intp(topic["is repeatable"])) &&
       (!member(topic, "responses") || isValidResponse(topic["responses"])) && 
       (!member(topic, "criteria") || isValidCriteria(topic["criteria"])) &&
       (!member(topic, "trigger") || isValidTrigger(topic)))
    {
        topics[key] = topic + ([ ]);
        ret = 1;
    }
    return ret;
}

private nomask string parseTargetMethod(string match)
{
    string ret = "ERROR";

    string query = regreplace(match, "##(.*)##", "\\1");
    string *arguments = explode(query, "::");

    object actor = this_player();

    if((sizeof(arguments) > 1) && arguments[1] &&
        present(arguments[1], environment(this_player())))
    {
        actor = present(arguments[1], environment(this_player()));
    }

    if(objectp(actor))
    {
        switch(arguments[0])
        {
            case "TN":
            {
                ret = actor->query_name();
                break;
            }
            case "TP":
            {
                ret = actor->query_possessive();
                break;
            }
            case "TO":
            {
                ret = actor->query_objective();
                break;
            }
            case "TR":
            {
                ret = actor->query_pronoun();
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return ret;

}

private string parseEfunCall(string match)
{
    string ret = "ERROR";

    // This match was found to be of the form efun::type::obj::function
    // the only supported efun right now is call_other
    // type can be any of: room, key (into persistentObjects), OR filename
    // obj is either this, the key into persistentObjects, OR a file path.
    // function is a method on the called object. This method MUST return a
    // string.
    string *arguments = explode(match, "::");
    if(sizeof(arguments) == 4)
    {
        switch(arguments[0])
        {
            case "##call_other":
            {
                switch(arguments[1])
                {
                    case "key":
                    {
                        if(member(objectList, arguments[2]) &&
                           objectp(objectList[arguments[2]]))
                        {
                            ret = call_other(objectList[arguments[2]],
                                             arguments[3]);
                        }

                        break;
                    }
                    case "file":
                    {
                        if(file_size(arguments[2]) > 0)
                        {
                            ret = call_other(arguments[2], arguments[3]);
                        }
                        break;
                    }
                    case "target":
                    {
                        if(present(arguments[2], environment(this_player())))
                        {
                            ret = call_other(present(arguments[2],
                                  environment(this_player())), arguments[3]);
                        }
                        break;
                    }
                    case "this":
                    {
                        ret = call_other(this_object(), arguments[3]);
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return ret;
}

private string parseTemplate(string template)
{
    // Options: ##TN[::target]## - target->query_name() (default this_player)
    //          ##TP[::target]## - target->query_possessive()
    //          ##TO[::target]## - target->query_objective()
    //          ##TR[::target]## - target->query_pronoun()
    //          @S@ - Color for speaking text
    //          @D@ - Description color
    //          @A@action@E@ - Action color
    //          ##efun::key|file|target|this::object|filename|this::function##

    // Replace target directives
    string ret = regreplace(template, "##T[PNOR](::[a-zA-Z]+)*##",
        #'parseTargetMethod,1);

    // Replace method calls
    ret = regreplace(ret,
        "##([^:]+)::(key|file|target|this)::([^:]+)::([a-zA-Z0-9_])+",
        #'parseEfunCall,1);

    // Apply colors
    ret = regreplace(ret, "@S@", Speech,1);
    ret = regreplace(ret, "@D@", Desc,1);
    ret = regreplace(ret, "@A@((.+))@E@", Action("\\1"),1);
    ret += End;

    return ret;
}

public nomask string awaitingResponse()
{
    return (this_player() &&
            member(responseMap, this_player()->query_real_name())) ?
            responseMap[this_player()->query_real_name()] : 0;
}

private nomask int checkCriteria(mapping response) 
{
    int ret = 1;

    //TODO: Add a criteria checker

    return ret;
}

private nomask string displayResponse(mapping response)
{
    string ret;
    if(mappingp(response) && member(response, "template"))
    {
        // environment(this_player()) already established
        ret = parseTemplate(response["template"]);
    }        
    return ret;
}

private nomask void displayResponses(mapping responses)
{
    foreach(string response : m_indices(responses))
    {
        if(checkCriteria(responses[response]))
        {
            // environment(this_player()) already established
            string responseText = displayResponse(responses[response]);
            if(responseText)
            {
                string writeMsg = regreplace(responseText, "#s#", "", 1);
                writeMsg = regreplace(writeMsg, "@@TN@@", "You", 1);
                writeMsg = regreplace(writeMsg, "@@Tn@@", "you", 1);
                write(format(Action(response) + ": " + writeMsg, 78));
            }
        }
    }
    ignoreTalk = 0;
}

private nomask void executeTrigger(string method)
{
    call_other(this_object(), method);
}

private nomask varargs int speakMessage(string key, int noSaveState)
{
    int ret = 0;

    if(this_player() && mappingp(topics[key]) &&
       member(topics[key], "template") &&
       checkCriteria(topics[key]))
    {
        tell_room(environment(this_player()),
                  format(parseTemplate(topics[key]["template"]), 78));
                  
        if(!noSaveState)
        {
            responseMap[this_player()->query_real_name()] = key;          
        }

        if(member(topics[key], "responses") &&
           mappingp(topics[key]["responses"]))
        {
            ignoreTalk = 1;
            call_out("displayResponses", 3, topics[key]["responses"]);
        }
        
        if(member(topics[key], "trigger"))
        {
            executeTrigger(topics[key]["trigger"]);
        }
        if(member(topics[key], "event"))
        {
            sendStateEvent(topics[key]["event"]);
        }        
        ret = 1;
    }
    return ret;
}

private nomask int respondToNPC(string str)
{
    int ret = 0;

    string verb = query_verb();
    string responseTo = awaitingResponse();
    if(verb && responseTo && !ignoreTalk)
    {
        if(member(topics[responseTo], "responses") &&
           member(topics[responseTo]["responses"], verb))
        {
            ret = 1;
            string responseText = "@@TN@@ say#s#, " +
                displayResponse(topics[responseTo]["responses"][verb]);
    
            if(responseText && responseText != "")
            {            
                string sayMsg = 
                    regreplace(responseText, "#s#", "s", 1);
                sayMsg = regreplace(sayMsg, "@@T[Nn]@@",
                    this_player()->query_name(), 1);
                say(format("\n" + sayMsg + "\n\n", 78));
                
                string writeMsg = regreplace(responseText, "#s#", "", 1);
                writeMsg = regreplace(writeMsg, "@@TN@@", "You", 1);
                writeMsg = regreplace(writeMsg, "@@Tn@@", "you", 1);
                write(format("\n" + writeMsg + "\n\n", 78));
            }
            if(member(topics[responseTo]["responses"][verb], "trigger"))
            {
                executeTrigger(topics[responseTo]["responses"][verb]["trigger"]);
            }            
            if(member(topics[responseTo]["responses"][verb], "event"))
            {
                sendStateEvent(topics[responseTo]["responses"][verb]["event"]);
            }                        
            if(member(topics[responseTo]["responses"][verb], "npc response"))
            {
                ignoreTalk = 1;
                call_out("speakMessage", 1, 
                    topics[responseTo]["responses"][verb]["npc response"]);
            }
        }
    }
    return ret;
}

public nomask int repeatMessage(string str)
{
    int ret = 0;

    string responseTo = awaitingResponse();
    if(responseTo)
    {
        ret = speakMessage(responseTo);
    }
    return ret;
}

public nomask int talk(string str)
{
    int ret = 0;
    string responseTo = awaitingResponse();
//    if(responseTo)
//    {
//        if(member(topics[responseTo])
//    }
    speakMessage(responseTo ? responseTo : defaultMessage);
    return 1;
}

public void init()
{
    // this ugly slice of hell adds all of the possible conversation actions
    foreach(string conversation : m_indices(topics))
    {
        if(mappingp(topics[conversation]) &&
           member(topics[conversation], "responses") &&
           mappingp(topics[conversation]["responses"]))
        {
            foreach(string response :
                m_indices(topics[conversation]["responses"]))
            {
                add_action("respondToNPC", response);
            }
        }

    }
    add_action("repeatMessage", "repeat");
    add_action("talk", "talk");
}


