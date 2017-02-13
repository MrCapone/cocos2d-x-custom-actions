//
//  Created by Dmitry on 20.10.14.
//  Copyright (c) 2014 Lukyanov D. M. All rights reserved.
//

#ifndef __cocos_sandbox__MyActionInterval__
#define __cocos_sandbox__MyActionInterval__

#include <cocos2d.h>

/**  Rotates a CCNode object to a certain angle around
 a certain rotation point by modifying it's rotation
 attribute and position.
 The direction will be decided by the shortest angle.
 */
class RotateAroundTo : public cocos2d::RotateTo
{ 
public:
    
    /** creates the action */
    static RotateAroundTo* create(float duration, float dstAngle, cocos2d::Vec2 rotationPoint);
    /** initializes the action */
    bool init(float duration, float dstAngle, cocos2d::Vec2 rotationPoint);
    
    virtual ~RotateAroundTo() {}
    
protected:
    
    virtual void startWithTarget(cocos2d::Node *target);
    
    virtual void update(float time);

private:

	cocos2d::Vec2 rotationPoint_;
	cocos2d::Vec2 startPosition_;

	float dstAngle_;
	float startAngle_;
	float diffAngle_;

};

/** Rotates a CCNode object clockwise around a certain
 rotation point a number of degrees by modiying its
 rotation attribute and position.
 */
class RotateAroundBy : public cocos2d::RotateBy
{
public:
    
    /** creates the action */
    static RotateAroundBy* create(float duration, float angle, cocos2d::Vec2 rotationPoint);
    /** initializes the action */
    bool init(float duration, float angle, cocos2d::Vec2 rotationPoint);
    
    virtual ~RotateAroundBy() {}
    
protected:
    
    virtual void startWithTarget(cocos2d::Node *target);
    
    virtual void update(float time);

private:

	cocos2d::Vec2 rotationPoint_;
	cocos2d::Vec2 startPosition_;

	float startAngle_;
	float angle_;

};

/**  Moves a CCNode object to a certain angle around
 a certain rotation point by modifying it's position.
 The direction will be decided by the shortest angle.
 */
class MoveAroundTo : public cocos2d::RotateTo
{ 
public:
    
    /** creates the action */
    static MoveAroundTo* create(float duration, float dstAngle, cocos2d::Vec2 rotationPoint);
    /** initializes the action */
    bool init(float duration, float dstAngle, cocos2d::Vec2 rotationPoint);
    
    virtual ~MoveAroundTo() {}
    
protected:
    
    virtual void startWithTarget(cocos2d::Node *target);
    
    virtual void update(float time);

private:

	cocos2d::Vec2 rotationPoint_;
	cocos2d::Vec2 startPosition_;

	float dstAngle_;
	float startAngle_;
	float diffAngle_;
};

/** Moves a CCNode object clockwise around a certain
 rotation point a number of degrees by modiying its
 position.
 */

class MoveAroundBy : public cocos2d::RotateBy
{
public:
    
    /** creates the action */
    static MoveAroundBy* create(float duration, float angle, cocos2d::Vec2 rotationPoint);
    /** initializes the action */
    bool init(float duration, float angle, cocos2d::Vec2 rotationPoint);
    
    virtual ~MoveAroundBy() {}
    
protected:
    
    virtual void startWithTarget(cocos2d::Node *target);
    
    virtual void update(float time);

private:

	cocos2d::Vec2 rotationPoint_;
	cocos2d::Vec2 startPosition_;

	float startAngle_;
	float angle_;
};

/**  Create fake effect of 3D rotation CCNode around X axis
 */
class FakeRotateX : public cocos2d::RotateTo
{
public:
    /** creates the action with default dept = 6 */
    static FakeRotateX* create(float duration, float startAngle, float dstAngle, float depth = 6.0f);
    /** initializes the action */
    bool init(float duration, float startAngle, float dstAngle, float depth);

    virtual ~FakeRotateX() {}

protected:

    virtual void startWithTarget(cocos2d::Node *target);

    virtual void update(float time);

private:

	float startAngle_;
	float dstAngle_;
	float diffAngle_;
	float radius_;
	float depth_;

	cocos2d::Sprite *target_;
};

/**  Create fake effect of 3D rotation CCNode around Y axis
 */
class FakeRotateY : public cocos2d::RotateTo
{
public:
    /** creates the action with default dept = 6 */
    static FakeRotateY* create(float duration, float startAngle, float dstAngle, float depth = 6.0f);
    /** initializes the action */
    bool init(float duration, float startAngle, float dstAngle, float depth);

    virtual ~FakeRotateY() {}

protected:

    virtual void startWithTarget(cocos2d::Node *target);

    virtual void update(float time);

private:

	float startAngle_;
	float dstAngle_;
	float diffAngle_;
	float radius_;
	float depth_;

	cocos2d::Sprite *target_;
};

/**  Create animation of digital counter
 */
class LabelCounter : public cocos2d::ActionInterval
{
public:
    /** creates the action with initial value = 0 */
    static LabelCounter* create(float duration, int finalValue, int initialValue = 0.0f);
    /** initializes the action */
    bool init(float duration, int finalValue, int initialValue);

    virtual ~LabelCounter() {}
    
    virtual void setBeforeText(std::string text);
    
    virtual void setAfterText(std::string text);

protected:

    virtual void startWithTarget(cocos2d::Node *target);

    virtual void update(float time);

    virtual void setValue(int value);

    cocos2d::Label *target_;
    
    std::string _beforeText;
    std::string _afterText;

private:

    int finalValue_;
    int initialValue_;

    int step_;
};

/**  Create animation of timer counter
 */
class LabelTimeCounter : public LabelCounter
{
public:
    /** creates the action with initial value = 0 */
    static LabelTimeCounter* create(float duration, int finalValue, int initialValue = 0.0f);
    /** initializes the action */
    bool init(float duration, int finalValue, int initialValue);

    virtual ~LabelTimeCounter() {}

protected:

    virtual void setValue(int value);

};

#endif /* defined(__cocos_sandbox__MyActionInterval__) */
