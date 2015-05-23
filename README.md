# CYPullRefresh
use pull-refresh and load-more easily

## basic use
First, It's very easy to implement pull-refresh and load-more feature by CYPullRefresh. Just import UIScrollView+CYPullRefresh category. Init by two lines of code.
```objective-c
- (void)cy_addPullDownHanlder:(CYPullRefreshBlock)handler topView:(UIView<CYPullRefreshViewProtocol> *)topView;
- (void)cy_addPullUpHandler:(CYPullRefreshBlock)handler bottomView:(UIView<CYPullRefreshViewProtocol> *)bottomView;
```

## sample
`see demo project`
```objective-c
    CYPullRefreshSimpleBottomView *bottomView = [[CYPullRefreshSimpleBottomView alloc] init];
    CYPullRefreshSimpleTopView *topView = [[CYPullRefreshSimpleTopView alloc] init];
    
    UITableView *tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    tableView.backgroundView = nil;
    tableView.delegate = self;
    tableView.dataSource = self;
    [tableView cy_addPullDownHanlder:^{
        [self reloadData];
    } topView:topView];
    [tableView cy_addPullUpHandler:^{
        [self loadMore];
    } bottomView:bottomView];
    [tableView cy_setPullUpEnable:NO];
    [self.view addSubview:tableView];
    
    _theTableView = tableView;
    
    [_theTableView cy_triggerLoadWithState:PullDownLoadState];
```
### reloadData
add this after finish loading data
```objective-c
    [_theTableView reloadData];
    [_theTableView cy_stopLoadWithState:PullDownLoadState];
    [_theTableView cy_setHasMoreData:_dataArray.count >= _limitNum ? YES : NO];
    [_theTableView cy_setPullUpEnable:YES];
```
### loadMore
add this after finish loading data
```objective-c
    [_theTableView reloadData];
    [_theTableView cy_stopLoadWithState:PullUpLoadState];
    [_theTableView cy_setHasMoreData:dataArray.count >= _limitNum ? YES : NO];
```

## custom loading view
You can custom your pull refresh view by creating a custom view confirming to CYPullRefreshViewProtocol. For different state, load different UI.For more information, see CYPullRefreshSimpleTopView and CYPullRefreshSimpleBottomView. 

In this way, you can do high customization without changing source code of CYPullRefresh. 

## CocoaPods
`pod 'CYPullRefresh'`
