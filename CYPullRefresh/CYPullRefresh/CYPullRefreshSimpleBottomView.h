//
//  CYPullRefreshSimpleBottomView.h
//  zuimei
//
//  Created by jason on 15/5/23.
//  Copyright (c) 2015年 chenyang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIScrollView+CYPullRefresh.h"

@interface CYPullRefreshSimpleBottomView : UIView <CYPullRefreshViewProtocol>

@property (nonatomic, readonly) UILabel *stateLabel;

@end