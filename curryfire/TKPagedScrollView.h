//
//  TKPagedScrollView.h
//  Created by Devin Ross on 6/18/15.
//
/*
 
 curryfire || https://github.com/devinross/curry-fire
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 
 */

@import curry;
@import UIKit;

@class TKPagedScrollView;

@protocol TKPagedScrollViewDelegate <NSObject>

@optional

- (void) pagedScrollViewDidScroll:(TKPagedScrollView *)scrollView;

- (void) pagedScrollView:(TKPagedScrollView *)scrollView didMoveToPage:(NSInteger)page;

- (void) pagedScrollViewWillBeginDragging:(TKPagedScrollView *)scrollView;
- (void) pagedScrollViewDidEndDragging:(TKPagedScrollView *)scrollView willDecelerate:(BOOL)decelerate;

- (void) pagedScrollViewWillBeginDecelerating:(TKPagedScrollView *)scrollView;
- (void) pagedScrollViewDidEndDecelerating:(TKPagedScrollView *)scrollView;
- (void) pagedScrollViewDidEndScrollingAnimation:(TKPagedScrollView *)scrollView;

- (BOOL) pagedScrollViewShouldScrollToTop:(TKPagedScrollView *)scrollView;
- (void) pagedScrollViewDidScrollToTop:(TKPagedScrollView *)scrollView;


@end


typedef NS_ENUM(NSUInteger, TKPageScrollDirection) {
    TKPageScrollDirectionVertical,
    TKPageScrollDirectionHorizontal
};


@interface TKPagedScrollView : UIView

- (id) initWithFrame:(CGRect)frame direction:(TKPageScrollDirection)direction;

@property (nonatomic,readonly) TKPageScrollDirection scrollDirection;

@property (nonatomic,strong) UIScrollView *scrollView;
@property (nonatomic,strong) NSArray *pages;
@property (nonatomic,assign) NSInteger currentPage;

@property (nonatomic,weak) id<TKPagedScrollViewDelegate>delegate;

- (void) scrollToPreviousPage;
- (void) scrollToNextPage;

- (void) scrollToPage:(NSInteger)page animated:(BOOL)animated;

@end