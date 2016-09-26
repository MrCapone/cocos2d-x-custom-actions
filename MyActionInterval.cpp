//
//  Created by Dmitry on 20.10.14.
//  Copyright (c) 2014 Lukyanov D. M. All rights reserved.
//

#include "MyActionInterval.h"

USING_NS_CC;

//p'x = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox
//p'y = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy

// RotateAroundTo

RotateAroundTo* RotateAroundTo::create(float duration, float dstAngle, Vec2 rotationPoint)
{
    RotateAroundTo *action = new (std::nothrow) RotateAroundTo();
    action->autorelease();
    
    if (action->init(duration, dstAngle, rotationPoint) ) {
        return action;
    }
    
    return nullptr;
}

bool RotateAroundTo::init(float duration, float dstAngle, Vec2 rotationPoint)
{
    if (RotateTo::initWithDuration(duration, dstAngle, dstAngle)) {
        rotationPoint_ = rotationPoint;
        dstAngle_ = dstAngle;
        
        return true;
    }
    
    return false;
}

void RotateAroundTo::startWithTarget(Node *target)
{
    RotateTo::startWithTarget(target);
    
    startAngle_ = target->getRotation();
    calculateAngles(startAngle_, diffAngle_, dstAngle_);
}

void RotateAroundTo::update(float time)
{
    float x = cos(CC_DEGREES_TO_RADIANS(-diffAngle_*time)) * ((startPosition_.x)-rotationPoint_.x) - sin(CC_DEGREES_TO_RADIANS(-diffAngle_*time)) * ((startPosition_.y)-rotationPoint_.y) + rotationPoint_.x;
    float y = sin(CC_DEGREES_TO_RADIANS(-diffAngle_*time)) * ((startPosition_.x)-rotationPoint_.x) + cos(CC_DEGREES_TO_RADIANS(-diffAngle_*time)) * ((startPosition_.y)-rotationPoint_.y) + rotationPoint_.y;
    
    _target->setPosition(x, y);
    _target->setRotation( (startAngle_ + diffAngle_ * time ) );
}

// RotateAroundBy

RotateAroundBy* RotateAroundBy::create(float duration, float angle, Vec2 rotationPoint)
{
    RotateAroundBy *action = new (std::nothrow) RotateAroundBy();
    action->autorelease();
    
    if (action->init(duration, angle, rotationPoint) ) {
        return action;
    }
    
    return nullptr;
}

bool RotateAroundBy::init(float duration, float angle, Vec2 rotationPoint)
{
    if (RotateBy::initWithDuration(duration, angle, angle)) {
        rotationPoint_ = rotationPoint;
        angle_ = angle;
        
        return true;
    }
    
    return false;
}

void RotateAroundBy::startWithTarget(Node *target)
{
    RotateBy::startWithTarget(target);
    
    startPosition_ = target->getPosition();
    startAngle_ = target->getRotation();
}

void RotateAroundBy::update(float time)
{
    float x = cos(CC_DEGREES_TO_RADIANS(-angle_*time)) * ((startPosition_.x)-rotationPoint_.x) - sin(CC_DEGREES_TO_RADIANS(-angle_*time)) * ((startPosition_.y)-rotationPoint_.y) + rotationPoint_.x;
    float y = sin(CC_DEGREES_TO_RADIANS(-angle_*time)) * ((startPosition_.x)-rotationPoint_.x) + cos(CC_DEGREES_TO_RADIANS(-angle_*time)) * ((startPosition_.y)-rotationPoint_.y) + rotationPoint_.y;
    
    _target->setPosition(x, y);
    _target->setRotation( (startAngle_ + angle_ * time ) );
}

// MoveAroundTo

MoveAroundTo* MoveAroundTo::create(float duration, float dstAngle, Vec2 rotationPoint)
{
    MoveAroundTo *action = new (std::nothrow) MoveAroundTo();
    action->autorelease();
    
    if (action->init(duration, dstAngle, rotationPoint) ) {
        return action;
    }
    
    return nullptr;
}

bool MoveAroundTo::init(float duration, float dstAngle, Vec2 rotationPoint)
{
    if (RotateTo::initWithDuration(duration, dstAngle, dstAngle)) {
        rotationPoint_ = rotationPoint;
        dstAngle_ = dstAngle;
        
        return true;
    }
    
    return false;
}

void MoveAroundTo::startWithTarget(Node *target)
{
    RotateTo::startWithTarget(target);
    
    startAngle_ = target->getRotation();
    calculateAngles(startAngle_, diffAngle_, dstAngle_);
}

void MoveAroundTo::update(float time)
{
    float x = cos(CC_DEGREES_TO_RADIANS(-diffAngle_*time)) * ((startPosition_.x)-rotationPoint_.x) - sin(CC_DEGREES_TO_RADIANS(-diffAngle_*time)) * ((startPosition_.y)-rotationPoint_.y) + rotationPoint_.x;
    float y = sin(CC_DEGREES_TO_RADIANS(-diffAngle_*time)) * ((startPosition_.x)-rotationPoint_.x) + cos(CC_DEGREES_TO_RADIANS(-diffAngle_*time)) * ((startPosition_.y)-rotationPoint_.y) + rotationPoint_.y;
    
    _target->setPosition(x, y);
}

// MoveAroundBy

MoveAroundBy* MoveAroundBy::create(float duration, float angle, Vec2 rotationPoint)
{
    MoveAroundBy *action = new (std::nothrow) MoveAroundBy();
    action->autorelease();
    
    if (action->init(duration, angle, rotationPoint) ) {
        return action;
    }
    
    return nullptr;
}

bool MoveAroundBy::init(float duration, float angle, Vec2 rotationPoint)
{
    if (RotateBy::initWithDuration(duration, angle, angle)) {
        rotationPoint_ = rotationPoint;
        angle_ = angle;
        
        return true;
    }
    
    return false;
}

void MoveAroundBy::startWithTarget(Node *target)
{
    RotateBy::startWithTarget(target);
    
    startPosition_ = target->getPosition();
    startAngle_ = target->getRotation();
}

void MoveAroundBy::update(float time)
{
    float x = cos(CC_DEGREES_TO_RADIANS(-angle_*time)) * ((startPosition_.x)-rotationPoint_.x) - sin(CC_DEGREES_TO_RADIANS(-angle_*time)) * ((startPosition_.y)-rotationPoint_.y) + rotationPoint_.x;
    float y = sin(CC_DEGREES_TO_RADIANS(-angle_*time)) * ((startPosition_.x)-rotationPoint_.x) + cos(CC_DEGREES_TO_RADIANS(-angle_*time)) * ((startPosition_.y)-rotationPoint_.y) + rotationPoint_.y;
    
    _target->setPosition(x, y);
}

// FakeRotateX

FakeRotateX* FakeRotateX::create(float duration, float startAngle, float dstAngle, float depth)
{
    FakeRotateX *action = new (std::nothrow) FakeRotateX();
    action->autorelease();

    if (action->init(duration, startAngle, dstAngle, depth) ) {
        return action;
    }

    return nullptr;
}

bool FakeRotateX::init(float duration, float startAngle, float dstAngle, float depth)
{
    if (RotateTo::initWithDuration(duration, dstAngle, dstAngle)) {
        startAngle_ = startAngle;
        dstAngle_ = dstAngle;
        depth_ = depth;

        target_ = nullptr;

        return true;
    }

    return false;
}

void FakeRotateX::startWithTarget(Node *target)
{
    RotateTo::startWithTarget(target);

    radius_ = target->getContentSize().height / 2.0;

    calculateAngles(startAngle_, diffAngle_, dstAngle_);

    target_ = dynamic_cast<Sprite *>(target); //dynamic_cast maybe overhead, but this action works only with sprites. todo: find better solution

    CCASSERT(target_, "this action can be used only with sprite");
}

void FakeRotateX::update(float time)
{
    PolygonInfo pi = target_->getPolygonInfo();

	pi.triangles.verts[0].vertices.y = cosf(-CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ + radius_;
    pi.triangles.verts[0].vertices.x = ( sinf(-CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_) / depth_;

    pi.triangles.verts[1].vertices.y = cosf(M_PI - CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ + radius_;
    pi.triangles.verts[1].vertices.x = ( sinf(M_PI - CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ ) / depth_;

    pi.triangles.verts[2].vertices.y = cosf(CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ + radius_;
    pi.triangles.verts[2].vertices.x = ( sinf(CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ ) / depth_ + target_->getContentSize().width;

    pi.triangles.verts[3].vertices.y = cosf(M_PI + CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ + radius_;
    pi.triangles.verts[3].vertices.x = ( sinf(M_PI + CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_) / depth_ + target_->getContentSize().width;

    target_->setPolygonInfo(pi);
}

// FakeRotateY

FakeRotateY* FakeRotateY::create(float duration, float startAngle, float dstAngle, float depth)
{
    FakeRotateY *action = new (std::nothrow) FakeRotateY();
    action->autorelease();

    if (action->init(duration, startAngle, dstAngle, depth) ) {
        return action;
    }

    return nullptr;
}

bool FakeRotateY::init(float duration, float startAngle, float dstAngle, float depth)
{
    if (RotateTo::initWithDuration(duration, dstAngle, dstAngle)) {
        startAngle_ = startAngle;
        dstAngle_ = dstAngle;
        depth_ = depth;

        target_ = nullptr;

        return true;
    }

    return false;
}

void FakeRotateY::startWithTarget(Node *target)
{
    RotateTo::startWithTarget(target);

    radius_ = target->getContentSize().width / 2.0;

    calculateAngles(startAngle_, diffAngle_, dstAngle_);

    target_ = dynamic_cast<Sprite *>(target); //dynamic_cast maybe overhead, but this action works only with sprites. todo: find better solution

    CCASSERT(target_, "this action can be used only with sprite");
}

void FakeRotateY::update(float time)
{
    PolygonInfo pi = target_->getPolygonInfo();

    pi.triangles.verts[0].vertices.x = cosf(M_PI + CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ + radius_;
    pi.triangles.verts[0].vertices.y = ( sinf(M_PI + CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_) / depth_ + target_->getContentSize().height;

    pi.triangles.verts[1].vertices.x = cosf(M_PI - CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ + radius_;
    pi.triangles.verts[1].vertices.y = ( sinf(M_PI - CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ ) / depth_;

    pi.triangles.verts[2].vertices.x = cosf(CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ + radius_;
    pi.triangles.verts[2].vertices.y = ( sinf(CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ ) / depth_ + target_->getContentSize().height;

    pi.triangles.verts[3].vertices.x = cosf(-CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_ + radius_;
    pi.triangles.verts[3].vertices.y = ( sinf(-CC_DEGREES_TO_RADIANS(startAngle_ + diffAngle_*time) ) * radius_) / depth_;

    target_->setPolygonInfo(pi);
}

LabelCounter* LabelCounter::create(float duration, int finalValue, int initialValue)
{
    LabelCounter *action = new (std::nothrow) LabelCounter();
    action->autorelease();

    if (action->init(duration, finalValue, initialValue) ) {
        return action;
    }

    return nullptr;
}

bool LabelCounter::init(float duration, int finalValue, int initialValue)
{
    if (ActionInterval::initWithDuration(duration)) {
        finalValue_ = finalValue;
        initialValue_ = initialValue;

        target_ = nullptr;

        return true;
    }

    return false;
}

void LabelCounter::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);

    step_ = finalValue_ - initialValue_;

    target_ = dynamic_cast<Label *>(target); //dynamic_cast maybe overhead, but this action works only with labels. todo: find better solution

    CCASSERT(target_, "this action can be used only with label");

    this->setValue(initialValue_);
}

void LabelCounter::update(float time)
{
    int value = initialValue_ + step_ * time;

    this->setValue(value);
}

void LabelCounter::setValue(int value)
{
    target_->setString(std::to_string(value));
}

LabelTimeCounter* LabelTimeCounter::create(float duration, int finalValue, int initialValue)
{
    LabelTimeCounter *action = new (std::nothrow) LabelTimeCounter();
    action->autorelease();

    if (action->init(duration, finalValue, initialValue) ) {
        return action;
    }

    return nullptr;
}

bool LabelTimeCounter::init(float duration, int finalValue, int initialValue)
{
    if (LabelCounter::init(duration, finalValue, initialValue)) {
        return true;
    }

    return false;
}

void LabelTimeCounter::setValue(int value)
{
    target_->setString(StringUtils::format("%02i:%02i:%02i", value / 3600, value % 3600 / 60, value % 60));
}